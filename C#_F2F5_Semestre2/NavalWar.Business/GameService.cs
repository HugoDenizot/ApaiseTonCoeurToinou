using NavalWar.DTO;
using NavalWar.DTO.WebDTO;
using NavalWar.DAL.Models;
using NavalWar.DAL;
using Microsoft.EntityFrameworkCore;

namespace NavalWar.Business

{
    public class GameService:IGameService
    {
       
        private readonly ISessionRepository _boardRepository;

        public GameService(ISessionRepository boardRepository)
        {
            _boardRepository = boardRepository;
        }


        public PlayerDTO CreatePlayer(string nomjoueur)

        {
            return _boardRepository.CreatePlayer(nomjoueur);

             
        }

        public BoardDto CreateBoard()
        {
            return _boardRepository.CreateBoard();
        }

        public PlayerDTO rejoindrePartie(int id_partie, string nomplayer)
        {
            return _boardRepository.rejoindrePartie(id_partie, nomplayer);
        }

        public SessionDTO GetSession(int id)
        {
                return _boardRepository.GetSession(id);
        }

        public BoardDto getBoard(int id)
        {
            return _boardRepository.getBoard(id);
        }

        public int[,] getShotBoard(int id)
        {
            return _boardRepository.getShotBoard(id).cellules;
        }

        public int[,] getPersonalBoard(int id)
        {
            return _boardRepository.getPersonalBoard(id).cellules;
        }

        public PlayerDTO GetPlayer(int id)
        {
            return _boardRepository.GetPlayer(id);
        }

        public string UpdatePlayer(int id,string s)
        {
            if (_boardRepository.updatePlayer(id, s).Result)
            {
                return s;
            }
            else
            {
                return null;
            }
        }

        public Task<bool> DeletePlayer(int id)
        {
            return _boardRepository.deletePlayer(id);
        }

        public Task<bool> DeleteSession(int id)
        {
            return _boardRepository.deleteSession(id);
        }

        public int ShotOn(TireDto t, int id)
        {
            return _boardRepository.shot(t,id);
        }

        public int[,] PlaceShips(int taille, int h, int posX, int posY, int playerId)
        {

            if (_boardRepository.placeShip(taille, h, posX, posY, playerId).Result)
            {
                return getPersonalBoard(playerId);
            }
            return null;
        }
   
    }
}
