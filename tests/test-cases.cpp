#include <gtest/gtest.h>
#include "string"
#include "vector"
#include "../include/searchserver.h"
#include "../include/invertedindex.h"
#include "../include/converterjson.h"

using namespace std;

void TestInvertedIndexFunctionality(const vector<string>& docs,
  const vector<string>& requests, const std::vector<vector<Entry>>& expected)
{
  std::vector<std::vector<Entry>> result;
  InvertedIndex idx;
  idx.UpdateDocumentBase(docs);

  for(auto& request : requests) {
    std::vector<Entry> word_count = idx.GetWordCount(request);
    result.push_back(word_count);
  }

  ASSERT_EQ(result, expected);
}

TEST(TestCaseInvertedIndex, TestBasic)
{
  const vector<string> docs =
  {
    "london is the capital of great britain",
    "big ben is the nickname for the Great bell of the striking clock"
  };

  const vector<string> requests = {"london", "the"};

  const vector<vector<Entry>> expected =
  {
    {
      {0, 1}
    },
    {
      {0, 1},
      {1, 3}
    }
  };

  TestInvertedIndexFunctionality(docs, requests, expected);
}

TEST(TestCaseInvertedIndex, TestBasic2)
{
  const vector<string> docs =
  {
    "milk milk milk milk water water water",
    "milk water water",
    "milk milk milk milk milk water water water water water",
    "americano cappuchino"
  };

  const vector<string> requests = {"milk", "water", "cappuchino"};
  const vector<vector<Entry>> expected =
  {
    {
      {0, 4}, {1, 1}, {2, 5}
    },
    {
      {0, 3}, {1, 2}, {2, 5}
    },
    {
      {3, 1}
    }
  };

  TestInvertedIndexFunctionality(docs, requests, expected);
}

TEST(TestCaseInvertedIndex, TestInvertedIndexMissingWord)
{
  const vector<string> docs =
  {
    "a b c d e f g h i j k l",
    "statement"
  };

  const vector<string> requests = {"m", "statement"};
  const vector<vector<Entry>> expected =
  {
    {
    },
    {
      {1, 1}
    }
  };

  TestInvertedIndexFunctionality(docs, requests, expected);
}

TEST(TestCaseSearchServer, TestTop)
{
  const vector<string> docs =
  {
    "london is the capital of great britain",
    "paris is the capital of france",
    "berlin is the capital of germany",
    "rome is the capital of italy",
    "madrid is the capital of spain",
    "lisboa is the capital of portugal",
    "bern is the capital of switzerland",
    "moscow is the capital of russia",
    "kiev is the capital of ukraine",
    "minsk is the capital of belarus",
    "astana is the capital of kazakhstan",
    "beijing is the capital of china",
    "tokyo is the capital of japan",
    "bangkok is the capital of thailand",
    "welcome to moscow the capital of russia the third rome",
    "amsterdam is the capital of netherlands",
    "helsinki is the capital of finland",
    "oslo is the capital of norway",
    "stockholm is the capital of sweden",
    "riga is the capital of latvia",
    "tallinn is the capital of estonia",
    "warsaw is the capital of poland",
  };

  const vector<string> request = {"moscow is the capital of russia"};

  const std::vector<vector<RelativeIndex>> expected =
  {
    {
      {7,  1},
      {14, 1},
      {0,  0.666666687},
      {1,  0.666666687},
      {2,  0.666666687},
      {3,  0.666666687},
      {4,  0.666666687},
      {5,  0.666666687},
      {6,  0.666666687},
      {8,  0.666666687},
      {9,  0.666666687},
      {10, 0.666666687},
      {11, 0.666666687},
      {12, 0.666666687},
      {13, 0.666666687},
      {15, 0.666666687},
      {16, 0.666666687},
      {17, 0.666666687},
      {18, 0.666666687},
      {19, 0.666666687},
      {20, 0.666666687},
      {21, 0.666666687}
    }
  };

  InvertedIndex idx;
  idx.UpdateDocumentBase(docs);
  SearchServer srv(idx);
  std::vector<vector<RelativeIndex>> result = srv.search(request);

  ASSERT_EQ(result, expected);
}

TEST(TestCaseSearchServer, TestSimple2)
{
  std::vector<std::string> docs =
  {
    "milk milk milk milk water water water",
    "milk water water",
    "milk milk milk milk milk water water water water water",
    "americano cappuccino"
  };

  const vector<string> request =
  {
    "milk water",
    "sugar"
  };

  const std::vector<vector<RelativeIndex>> expected =
  {
    {
      {2, 1},
      {0, 0.7},
      {1, 0.3}
    },
    {
    }
  };

  InvertedIndex idx;
  idx.UpdateDocumentBase(docs);
  SearchServer srv(idx);
  std::vector<vector<RelativeIndex>> result = srv.search(request);

  ASSERT_EQ(result, expected);
}

