#include "converterjson.h"
#include "json.hpp"
#include <vector>
#include <fstream>
#include <string>

std::vector<std::string> ConverterJSON::GetTextDocuments()
{
  std::vector<std::string> list;
  std::ifstream inconfig;
  inconfig.open("config.json", std::ios_base::in);
  if (!inconfig.is_open()) {
    std::cerr << "[FAIL] config file is missing" << std::endl;
  } else {
    nlohmann::json config;
    inconfig >> config;
    for (auto pathfile : config["files"]) {
      std::ifstream infile;
      infile.open(pathfile, std::ios_base::in);
      if (!infile.is_open()) {
        std::cerr << "[FAIL] " << pathfile << " is missing" << std::endl;
      } else {
        std::string str;
        while(getline(infile, str, infile.widen('\n'))) {
          list.push_back(str);
        }
      }
    }
  }

  inconfig.close();
  return list;
}

int ConverterJSON::GetTimeUpdate()
{
  std::ifstream in_config;
  in_config.open("config.json", std::ios_base::in);
  if (!in_config.is_open()) {
    std::cerr << "[FAIL] config file is missing" << std::endl;
  } else {
    nlohmann::json config;
    in_config >> config;
    return config["config"]["timer_sec"];
  }

  in_config.close();
  return 1;
}

int ConverterJSON::GetResponsesLimit()
{
  std::ifstream in_config;
  in_config.open("config.json", std::ios_base::in);
  if (!in_config.is_open()) {
    std::cerr << "[FAIL] config file is missing" << std::endl;
  } else {
    nlohmann::json config;
    in_config >> config;
    return config["config"]["max_responses"];
  }

  in_config.close();
  return 5;
}

std::vector<std::string> ConverterJSON::GetRequests()
{
  std::vector<std::string> list;
  std::ifstream in_req;
  in_req.open("requests.json", std::ios_base::in);
  if (!in_req.is_open()) {
    std::cerr << "[FAIL] requests file is missing" << std::endl;
  } else {
    nlohmann::json requests;
    in_req >> requests;
    for (auto request : requests["requests"]) {
      list.push_back(request);
    }
  }

  in_req.close();
  return list;
}

//void ConverterJSON::putAnswers(std::vector<std::vector<std::pair<int, float>>> answers)
void ConverterJSON::putAnswers(std::vector<std::vector<RelativeIndex>> answers)
{
  std::ofstream out_answers;
  out_answers.open("answers.json", std::ios_base::out);
  if (!out_answers.is_open()) {
    std::cerr << "[FAIL] answers file is missing" << std::endl;
  } else {
    nlohmann::json result;
    std::string text = "{ \"";
    for (size_t req {0}; req < answers.size(); req++) {
      std::string number_request = std::to_string(req);
      for (size_t size {number_request.size()}; size < 3; size++) { // дополняем номер запроса нулями
        number_request = "0" + number_request;
      }

      if (!answers[req].empty()) {
        result["answers"]["request" + number_request]["result"] = "true";
        if (answers[req].size() == 1) {
          result["answers"]["request" + number_request]
                ["0) docid_" + std::to_string(answers[req][0].doc_id)]
                ["rank"] = std::to_string(answers[req][0].rank);
        } else {
          size_t limit = GetResponsesLimit();
          for (size_t docs {0}; docs < answers[req].size() && docs < limit; docs++) {
//          for (auto x : answers[req]) {
            result["answers"]["request" + number_request]["relevance"]
              [std::to_string(docs) + ") docid_" + std::to_string(answers[req][docs].doc_id)]["rank"] =
                std::to_string(answers[req][docs].rank);
          }
        }
      } else {
        result["answers"]["request" + number_request]["result"] = "false";
      }
    }
      out_answers << result;
  }
  out_answers.close();
}
