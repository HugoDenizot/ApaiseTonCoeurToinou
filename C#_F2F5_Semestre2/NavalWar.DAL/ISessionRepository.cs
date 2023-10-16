using NavalWar.DAL.Models;
using NavalWar.DTO;
using NavalWar.DTO.WebDTO;

namespace NavalWar.DAL
{
    public interface ISessionRepository
    {
                
        public PlayerDTO CreatePlayer(string nomjoueur); //Fait

        public BoardDto CreateBoard(); //Fait

        public SessionDTO CreateSession(); //Fait
        public PlayerDTO rejoindrePartie(int id_partie, string nomplayer); //Fait
        public PlayerDTO GetPlayer(int id); //Fait
        public SessionDTO GetSession(int id); //Fait
        public BoardDto getBoard(int id); //Fait
        public BoardDto getPersonalBoard(int id); //Fait
        public BoardDto getShotBoard(int id); //Fait
        public Task<bool> UpdateBoard(BoardDto boardDto); //Fait

        public Task<bool> updatePlayer(int id, string s); //Fait

        public Task<bool> DeleteBoard(BoardDto boardDto); //Fait
        public Task<bool> deletePlayer(int id); //Fait

        public Task<bool> deleteSession(int id); //Fait

        public int shot(TireDto t, int id); //Fait

        public Task<bool> placeShip(int taille, int h, int posX, int posY, int playerId); //Fait

    }
}