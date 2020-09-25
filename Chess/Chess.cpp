#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>

#include "Tester.h"
#include "ChessPiece.h"
#include "ChessBoard.h"
#include "Repo.h"
#include "ServicePieces.h"
#include "UI.h"

int main()
{
    {
        Tester tester;
        tester.test_all();
        std::cout << "All tests passed!\n";
        RepoPointers<ChessPiece> repo;
        ChessBoard chessBoard;
        ServicePieces service = ServicePieces(repo, chessBoard);
        UI ui = UI(service);
        //ui.run_ui();
    }
    _CrtDumpMemoryLeaks();
}