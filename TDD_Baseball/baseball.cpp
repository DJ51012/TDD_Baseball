#include <stdexcept>

using namespace std;

struct GuessResult {
	bool solved;
	int strikes;
	int balls;
};

class Baseball {
public:
	explicit Baseball(const string& question)
		: question(question) {
	}

	GuessResult guess(const string& guessNumber) {
		assertIllegalArgument(guessNumber);
		GuessResult result = { false, 0, 0 };
		if (guessNumber == question) {
			return { true, 3, 0 };
		}
		else {
			for (int i = 0; i < MAX_COUNT; i++) {
				for (int j = 0; j < MAX_COUNT; j++) {
					if (guessNumber[i] == question[j]) {
						if (i == j)
							result.strikes++;
						else
							result.balls++;
						break;
					}
				}
			}
		}
		return result;
	}

private:
	void assertIllegalArgument(const string& guessNumber) {

		if (guessNumber.length() != MAX_COUNT) {
			throw length_error("Must be three letters.");
		}
		for (char ch : guessNumber) {
			if (ch >= '0' && ch <= '9') continue;
			throw invalid_argument("Must be number.");
		}
		if (isDuplicatedNumber(guessNumber))
			throw invalid_argument("Must not have the same number");
	}
	bool isDuplicatedNumber(const std::string& guessNumber) {
		return (guessNumber[0] == guessNumber[1]
			|| guessNumber[0] == guessNumber[2]
			|| guessNumber[1] == guessNumber[2]);
	}

	const int MAX_COUNT = 3;
	string question;
};