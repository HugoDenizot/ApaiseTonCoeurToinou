using Microsoft.EntityFrameworkCore;
using NavalWar.DAL.Models;
using NavalWar.DTO;
using NavalWar.DTO.WebDTO;
using AutoMapper;
using System.Security.Cryptography.X509Certificates;
using System.Runtime.Serialization;

namespace NavalWar.DAL
{
    // the equivalent of gamerepository
    public class SessionRepository : ISessionRepository
    {
        private readonly NavalContext _context;

        public SessionRepository(NavalContext context)
        {
            _context = context;
        }

        public SessionDTO GetSession(int id)
        {
            try
            {
                Session session = _context.Sessions.FirstOrDefault(x => x.ID == id);
                SessionDTO s = new SessionDTO { ID = session.ID,NameJoueurEnCours=session.NameJoueurEnCours };
                /*foreach(NavalWar.DAL.Models.Player p in session.players)
                {
                    PlayerDTO po= new PlayerDTO() {_id=p._id,_name=p._name };
                    s.players.Add(po);
                }*/
                return s;
            }
            catch (Exception)
            {
                throw;
            }
        }

        public PlayerDTO GetOtherPlayer(int id)
        {
            PlayerDTO p1 = GetPlayer(id);
            var listp = _context.Players.Where(x => x.PlayerSessionId==p1.SessionId);
            Player p2=null;
            foreach(Player p in listp)
            {
                if (p._id != id)
                {
                    p2= p;
                }
            }
            if(p2 == null)
            {
                return null;
            }
            PlayerDTO retour=Extension.toDTO(p2);
            return retour;
        }

        public PlayerDTO GetPlayer(int id)
        {
            try
            {
                Player player = _context.Players.FirstOrDefault(x => x._id == id);
                if(player != null) {
                    PlayerDTO s = new PlayerDTO
                    {
                        _id = player._id,
                        _name = player._name,
                        _personalBoard = player._personalBoard,
                        _shotBoard = player._shotBoard,
                        SessionId = player.PlayerSessionId,
                    };
                    return s;
                }
            }
            catch (Exception)
            {
                throw;
            }
            return null;
            
        }

        public BoardDto getBoard(int id)
        {

            var boardEntity = _context.Boards.FirstOrDefault(b => b.Id == id);
            if (boardEntity == null)
            {
                throw new InvalidOperationException($"Board for player with ID {id} not found.");
            }

            return Extension.toDto(boardEntity);
            //return _mapper.Map<BoardDto>(boardEntity);
        }

        public BoardDto getPersonalBoard(int id)
        {
            Player p = _context.Players.Find(id);
            if (p != null)
            {
                Board b = _context.Boards.Find(p._personalBoard);
                if (b != null)
                {
                    BoardDto board = Extension.toDto(b);
                    return board;
                }
                else
                {
                    Console.WriteLine("C'est b le problème");
                }
            }
            else
            {
                Console.WriteLine("C'est p le problème");
            }

            return null;
        }

        public BoardDto getShotBoard(int id)
        {
            Player p = _context.Players.Find(id);
            if (p != null)
            {
                Board b = _context.Boards.Find(p._shotBoard);
                if (b != null)
                {
                    BoardDto board = Extension.toDto(b);
                    return board;
                }
                else
                {
                    Console.WriteLine("C'est b le problème");
                }
            }
            else
            {
                Console.WriteLine("C'est p le problème");
            }

            return null;
        }
        public async Task<bool> UpdateBoard(BoardDto boardDto)
        {
            Board b=Extension.toEntity(boardDto);
            Board ancien_b = _context.Boards.Find(b.Id);
            if(ancien_b!=null)
            {
                ancien_b.cellules = b.cellules;
                _context.SaveChanges();
                return true;
            }
            return false;
        }
        public async Task<bool> updatePlayer(int id, string s)
        {
            Player player = _context.Players.Find(id);
            if (player != null)
            {
                player._name = s;
                _context.SaveChanges();
                return true;
            }
            else
            {
                return false;
            }
        }

        public PlayerDTO CreatePlayer(string nomjoueur)
        {
            BoardDto personnal = CreateBoard();
            BoardDto shoot = CreateBoard();
            SessionDTO session= CreateSession();
            PlayerDTO p = new PlayerDTO()
            {
                _name= nomjoueur,
                SessionId = session.ID,
                _personalBoard = personnal.Id,
                _shotBoard = shoot.Id,
            };
            Player paly = Extension.toEntity(p);
            _context.Players.Add(paly);
            _context.SaveChanges();
            p._id= paly._id;
            return p;
        }
        public BoardDto CreateBoard()
        {
            BoardDto b = new BoardDto();

            Board save = Extension.toEntity(b);
            Console.WriteLine(save.cellules);
            if (b.cellules != null)
            {
                _context.Boards.Add(save);
                _context.SaveChanges();
                b.Id = save.Id;
                return b;
            }
            else
            {
                ;
                return null;
            }
        }
        public SessionDTO CreateSession()
        {
            SessionDTO s = new SessionDTO();
            if (s != null)
            {
                Session session = Extension.toEntity(s);
                _context.Sessions.Add(session);
                _context.SaveChanges();
                s.ID = session.ID;
            }
            return s;

        }

        public async Task<bool> deletePlayer(int id)
        {
            Player p = _context.Players.Find(id);
            if (p != null)
            {
                _context.Players.Remove(p);
                _context.SaveChanges();
            }
            else
            {
                return false;
            }
            return true;
        }

        public async Task<bool> DeleteBoard(BoardDto boardDto)
        {
            Board b = _context.Boards.Find(boardDto.Id);
            if (b != null)
            {
                _context.Boards.Remove(b);
                _context.SaveChanges();
            }
            else
            {
                return false;
            }
            return true;
        }

        public async Task<bool> deleteSession(int id)
        {
            Session s = _context.Sessions.Find(id);
            if (s != null)
            {
                _context.Sessions.Remove(s);
                _context.SaveChanges();
            }
            else
            {
                return false;
            }
            return true;
        }

        public async Task<bool> placeShip(int taille, int h, int posX, int posY, int playerId)
        {
            Console.WriteLine("J'ai recu un bateau de taille " + taille + " de placement " + h +" a la pos " + posX + " " + posY);
            BoardDto board = getPersonalBoard(playerId);
            bool test=true;
            if (h == 0)
            {
                Console.WriteLine("Bien dans l'horizontale");
                if(posX+taille<= 9&&posX>=0&&posY>=0) {
                    
                    for(int i = 0; i < taille; i++)
                    {
                        if(board.cellules[posX+i, posY] != 0)
                        {
                            test = false;
                        }
                    }
                    if (test)
                    {
                        for (int i = 0; i < taille; i++)
                        {
                            board.cellules[posX+i, posY] = 1;
                        }
                        UpdateBoard(board);
                        Console.WriteLine("Bon le test");
                        return true;
                    }
                    else
                    {
                        Console.WriteLine("Pas bon le test");
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
            else
            {
                Console.WriteLine("Pas dans l'horizontale");
                if (posY + taille <= 9 && posX >= 0&&posY>=0)
                {

                    for (int i = 0; i < taille; i++)
                    {
                        if (board.cellules[posX,posY+i] != 0)
                        {
                            test = false;
                        }
                    }
                    if (test)
                    {
                        for (int i = 0; i < taille; i++)
                        {
                            board.cellules[posX, posY + i] = 1;
                        }
                        UpdateBoard(board);
                        Console.WriteLine("Bon le test");
                        return true;
                    }
                    else
                    {
                        Console.WriteLine("Pas bon le test");
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
        }
        public void changerTour(int id_session)
        {
            Session s = _context.Sessions.FirstOrDefault(x=>x.ID==id_session);
            if (s.NameJoueurEnCours == "Joueur1")
            {
                s.NameJoueurEnCours = "Joueur2";
            }
            else
            {
                s.NameJoueurEnCours = "Joueur1";
            }
            _context.SaveChanges();
        }
        public int shot(TireDto t, int id)
        {
            int globale=0, parliste;
            PlayerDTO other = GetOtherPlayer(id);
            BoardDto navOther = getPersonalBoard(other._id);
            BoardDto shot = getShotBoard(id);
            changerTour(other.SessionId);
            if(navOther != null)
            {
                if (navOther.cellules[t.posX,t.posY]==1|| navOther.cellules[t.posX, t.posY] == 2) {
                    navOther.cellules[t.posX,t.posY]=2;
                    shot.cellules[t.posX, t.posY] = 2;
                    
                }
                else
                {
                    navOther.cellules[t.posX, t.posY] = 3;
                    shot.cellules[t.posX, t.posY] = 3;
                }
                UpdateBoard(navOther);
                UpdateBoard(shot);
                for (int i = 0; i < 10; i++)
                {
                    for (int j = 0; j < 10; j++)
                    {
                        if (shot.cellules[i, j] == 2)
                        {
                            globale += 1;
                        }
                    }
                }

                if (globale == 17)
                {
                    return 2;
                }
                return 1;
            }
            {
                return 0;
            }
        }

        public PlayerDTO rejoindrePartie(int id_partie, string nomplayer)
        {
            int nombreDeLignes = _context.Players.Where(x => x.PlayerSessionId == id_partie).Count();
            if (nombreDeLignes == 1)
            {
                BoardDto personnal = CreateBoard();
                BoardDto shoot = CreateBoard();
                PlayerDTO p = new PlayerDTO()
                {
                    _name = nomplayer,
                    SessionId = id_partie,
                    _personalBoard = personnal.Id,
                    _shotBoard = shoot.Id,
                };
                Player paly = Extension.toEntity(p);
                try
                {
                    _context.Players.Add(paly);
                    _context.SaveChanges();
                    p._id = paly._id;
                    return p;
                }
                catch (Exception e)
                {
                    return null;
                }
            }
            else
            {
                return null;
            }
            
            
        }
    }
}
