import java.util.*;

public class TicTacToe {

    private static char[][] board = new char[3][3];
    private static Scanner scanner = new Scanner(System.in);
    private static Random random = new Random();

    public static void main(String[] args) {
        System.out.println("Select mode:");
        System.out.println("1) Two Players");
        System.out.println("2) One Player vs Bot");
        int mode = 0;
        while (mode != 1 && mode != 2) {
            System.out.print("Enter 1 or 2: ");
            if (scanner.hasNextInt()) {
                mode = scanner.nextInt();
            } else {
                scanner.next(); // clear invalid input
            }
        }
        initializeBoard();
        playGame(mode == 1);
    }

    private static void initializeBoard() {
        for (int i = 0; i < 3; i++) {
            Arrays.fill(board[i], ' ');
        }
    }

    private static void printBoard() {
        System.out.println();
        for (int i = 0; i < 3; i++) {
            System.out.printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
            if (i < 2) System.out.println("---+---+---");
        }
        System.out.println();
    }

    private static boolean checkWinner(char player) {
        // rows and cols
        for (int i = 0; i < 3; i++) {
            if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
                (board[0][i] == player && board[1][i] == player && board[2][i] == player))
                return true;
        }
        // diagonals
        if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
            (board[0][2] == player && board[1][1] == player && board[2][0] == player))
            return true;

        return false;
    }

    private static boolean isBoardFull() {
        for (int r = 0; r < 3; r++) 
            for (int c = 0; c < 3; c++) 
                if (board[r][c] == ' ') 
                    return false;
        return true;
    }

    private static void playerMove(char player) {
        while (true) {
            System.out.printf("Player %c - Enter your move (1-9): ", player);
            String input = scanner.next();
            int pos;
            try {
                pos = Integer.parseInt(input);
            } catch (NumberFormatException e) {
                System.out.println("Invalid input. Please enter a number 1-9.");
                continue;
            }
            if (pos < 1 || pos > 9) {
                System.out.println("Position must be between 1 and 9.");
                continue;
            }
            int row = (pos - 1) / 3;
            int col = (pos - 1) % 3;
            if (board[row][col] != ' ') {
                System.out.println("That spot is already taken.");
                continue;
            }
            board[row][col] = player;
            break;
        }
    }

    private static void botMove(char player) {
        List<int[]> available = new ArrayList<>();
        for (int r = 0; r < 3; r++) {
            for (int c = 0; c < 3; c++) {
                if (board[r][c] == ' ') {
                    available.add(new int[]{r, c});
                }
            }
        }
        int[] move = available.get(random.nextInt(available.size()));
        board[move[0]][move[1]] = player;
        int pos = move[0] * 3 + move[1] + 1;
        System.out.println("Bot (" + player + ") chose position " + pos);
    }

    private static void playGame(boolean twoPlayers) {
        System.out.println("Positions are numbered as follows:");
        System.out.println(" 1 | 2 | 3 ");
        System.out.println("---+---+---");
        System.out.println(" 4 | 5 | 6 ");
        System.out.println("---+---+---");
        System.out.println(" 7 | 8 | 9 ");

        char currentPlayer = 'X';

        while (true) {
            printBoard();
            if (twoPlayers || currentPlayer == 'X') {
                playerMove(currentPlayer);
            } else {
                botMove(currentPlayer);
            }

            if (checkWinner(currentPlayer)) {
                printBoard();
                if (twoPlayers || currentPlayer == 'X') {
                    System.out.println("Player " + currentPlayer + " wins!");
                } else {
                    System.out.println("Bot (" + currentPlayer + ") wins!");
                }
                break;
            }

            if (isBoardFull()) {
                printBoard();
                System.out.println("It's a draw!");
                break;
            }

            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }
}
