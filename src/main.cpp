#include "converterjson.h"
#include "invertedindex.h"
#include "searchserver.h"
#include "json.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <thread>

int main(int argc, char **argv)
{
  std::ifstream in;
  in.open("config.json", std::ios_base::in);
  if (!in.is_open()) {
    std::cerr << "[FAIL] config file is missing" << std::endl;
  } else {
    nlohmann::json config;
    in >> config;
    if (nullptr == config["config"]) {
      std::cerr << "[FAIL] config file is empty" << std::endl;
    } else {
      std::cout << "Starting " << config["config"]["name"] << " version "
                << config["config"]["version"] << std::endl;

      ConverterJSON converter;
      while(true) {
        std::this_thread::sleep_for(std::chrono::seconds(converter.GetTimeUpdate()));

        std::vector<std::string> listTextBlocks = converter.GetTextDocuments();
        std::vector<std::string> listRequests = converter.GetRequests();
        InvertedIndex idx;
        idx.UpdateDocumentBase(listTextBlocks);
        SearchServer server(idx);
        converter.putAnswers(server.search(listRequests));
      }
    }
  }

  in.close();
  std::cout << "program close" << std::endl;
}
