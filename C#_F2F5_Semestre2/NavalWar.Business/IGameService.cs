using NavalWar.DTO;
using NavalWar.DTO.WebDTO;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NavalWar.Business
{
    public interface IGameService 
    {

        public PlayerDTO CreatePlayer(string nomjoueur); //Fini

        public BoardDto CreateBoard(); // Fini
        public PlayerDTO rejoindrePartie(int id_partie, string nomplayer);

        public SessionDTO GetSession(int id); //Fait

        public PlayerDTO GetPlayer(int id); //Fini

        public int[,] getPersonalBoard(int id); //Fini

        public int[,] getShotBoard(int id); //Fini

        public string UpdatePlayer(int id,string s); //Fini
        public Task<bool> DeletePlayer(int id); //Fini

        public Task<bool> DeleteSession(int id); //A modifier pour supprimer après une partie

        public int ShotOn(TireDto t,int id); //Fini

        public int[,] PlaceShips(int taille,int h,int posX,int posY,int playerId); //Fini
    }
}
