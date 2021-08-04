all:
	@clang++ -std=c++11 -Wall -Wextra -Werror dual-n-back/main.cpp dual-n-back/dual-n-back.cpp dual-n-back/signal.cpp dual-n-back/generate_signals.cpp dual-n-back/collect_answers.cpp -o dual-n-back.a
	@./dual-n-back.a

clean:
	rm dual-n-back.a
