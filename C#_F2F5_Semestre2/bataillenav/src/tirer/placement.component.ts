import { Component } from '@angular/core';
import { AfterViewInit } from '@angular/core';

@Component({
  selector: 'app-tableau-boutons',
  templateUrl: './placement.component.html',
  styleUrls: ['./placement.component.css']
})

export class PlacementComponent implements AfterViewInit {
  rows = Array.from(Array(10).keys());
  cols = Array.from(Array(10).keys());

  

  ngAfterViewInit() {
    const container = document.getElementById("buttonsContainer");
    if (container) {
      for (let i = 0; i < 10; i++) {
        for (let j = 0; j < 10; j++) {
          const button = document.createElement("button");
          button.classList.add("container", "water");
          const buttonId = `${i};${j}`;
          button.id = buttonId;
          button.addEventListener('click', () => {
            this.place(button.id);
          });
          button.style.backgroundColor = 'grey';
          container.appendChild(button);
        }
      }
    } else {
      console.error('Element with ID "buttonsContainer" not found.');
    }
  }

  place(id:string){
    console.log("aaaa");
  }

  cellClicked(row: number, col: number) {
    alert("La cellule (" + row + "," + col + ") a été cliquée !");
  }

  public onButtonClick(buttonId: string): void {
    const button = document.getElementById(buttonId);
    console.log(button);
    if (button) {
      button.style.backgroundColor = 'red';
    }
  }
  
}