import { Component,OnInit, ViewChild, ElementRef, AfterViewInit } from '@angular/core';
import { HttpClient, HttpParams,HttpHeaders } from '@angular/common/http';
import {Router } from '@angular/router';
import { Observable } from 'rxjs';
import { FormsModule } from '@angular/forms';
import { AppModule } from '../app/app.module';

@Component({
  selector: 'app-rejoindre-partie',
  templateUrl: './rejoindre-partie.component.html',
  styleUrls: ['./rejoindre-partie.component.css'],
})
export class RejoindrePartieComponent implements AfterViewInit {
  @ViewChild('myInput') myInput: any;
  keys = ''; 
 
  onKeyUp(event:any) 
  {    
    localStorage.setItem("taillesSav",JSON.stringify([5,4,3,3,2]));
    console.log('Input value:', event.target.value);
    let apiUrl = `https://localhost:7080/api/GameArea/RejoindrePartie/${event.target.value}`    ;
    this.http.get<any>(apiUrl).subscribe(joueur => {
      if(joueur!=null){
        console.log(joueur);
        this.router.navigate(['placement'],{ queryParams: { id_player: joueur._id,id_session:joueur.sessionId,nom:joueur._name } });
      }else{
        alert("Pas le bon id de session ou session pleine");
      }
    });
  } 

  constructor(private http: HttpClient, private router : Router) { }
  ngAfterViewInit() {

  }

  getValue(element: ElementRef) {
    console.log(element.nativeElement.value);
  }

  onSubmit(){
    console.log('Input value:', this.myInput.nativeElement.value);
    let apiUrl = `https://localhost:7080/api/GameArea/RejoindrePartie/${this.myInput.nativeElement.value}`    ;
    this.http.get<any>(apiUrl).subscribe(joueur => {
      console.log(joueur);
    }); 
    //
    

  }
}
