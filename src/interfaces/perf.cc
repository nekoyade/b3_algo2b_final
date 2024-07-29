/*  Project name    : A2BF
 *  File name       : interfaces/perf.cc
 *
 *  2024 Keitaro Kamo (nekoyade)
 *
 */

#include "interfaces/perf.h"

#include <chrono>
#include <iomanip>
#include <iostream>
#include <string>

#include "models/alphabeta.h"
#include "models/board.h"
#include "models/cell.h"
#include "models/minimax.h"

namespace a2bf {

namespace {

double CalcElapsedTime(
        std::chrono::system_clock::time_point start,
        std::chrono::system_clock::time_point end) {
    return static_cast<double>(
        std::chrono::duration_cast<std::chrono::microseconds>(end - start)
        .count()/1000.0
    );
}

void PrintResults(
        double eval, double elapsed_time, long long int call_counter) {
    std::cout << "      Eval: " << eval << std::endl;
    std::cout << "      Elapsed time: "
        << std::scientific << std::setprecision(15) << elapsed_time
        << " ms" << std::endl;
    std::cout << "      Num. of calculated vertices: " << call_counter
        << std::endl;
}

}  // namespace

void PerformMinimax(
        MinimaxSolver& minimax, const Board& init,
        double (*evaluator)(const Board&, CellState), int n,
        std::string label) {
    std::cout << "  Minimax (" << label << ")" << std::endl;

    double eval;
    double average_elapsed_time;
    long long int call_counter;
    std::chrono::system_clock::time_point start, end;
    for (int i = 0; i < n; ++i) {
        start = std::chrono::system_clock::now();
        eval = minimax.Minimax(init, CellState::kDark, evaluator);
        end = std::chrono::system_clock::now();

        double elapsed_time = CalcElapsedTime(start, end);
        average_elapsed_time += elapsed_time;

        call_counter = minimax.call_counter();

        std::cout << "    [" << i + 1 << "/" << n << "] " << std::endl;
        PrintResults(eval, elapsed_time, call_counter);
    }
    average_elapsed_time /= n;

    std::cout << "    [Result]" << std::endl;
    PrintResults(eval, average_elapsed_time, call_counter);
}

void PerformAlphabeta(
        AlphabetaSolver& alphabeta, const Board& init,
        double (*evaluator)(const Board&, CellState), int n,
        std::string label) {
    std::cout << "  Alphabeta (" << label << ")" << std::endl;

    double eval;
    double average_elapsed_time;
    long long int call_counter;
    std::chrono::system_clock::time_point start, end;
    for (int i = 0; i < n; ++i) {
        start = std::chrono::system_clock::now();
        eval = alphabeta.Alphabeta(init, CellState::kDark, evaluator);
        end = std::chrono::system_clock::now();

        double elapsed_time = CalcElapsedTime(start, end);
        average_elapsed_time += elapsed_time;

        call_counter = alphabeta.call_counter();

        std::cout << "    [" << i + 1 << "/" << n << "] " << std::endl;
        PrintResults(eval, elapsed_time, call_counter);
    }
    average_elapsed_time /= n;

    std::cout << "    [Result]" << std::endl;
    PrintResults(eval, average_elapsed_time, call_counter);
}

}  // namespace a2bf
