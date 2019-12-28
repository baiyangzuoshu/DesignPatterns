import  {GameObject}  from './GameObject';
class   Sprite{}
export class   Graphics{
    draw(sprite:Sprite,x:number,y:number):void{}
}

export  interface   GraphicsComponent{
    update(bjorn:GameObject,graphics:Graphics):void;
}

export  class PlayerGraphicsComponent implements  GraphicsComponent{
    spriteStand_:Sprite=new Sprite;
    spriteLeft_:Sprite=new Sprite;
    spriteRight_:Sprite=new Sprite;

    update(bjorn:GameObject,graphics:Graphics):void{
        let sprite:Sprite=this.spriteStand_;
        if(bjorn.velocity<0){
            sprite=this.spriteLeft_;
        }
        else if(bjorn.velocity>0){
            sprite=this.spriteRight_;
        }

        graphics.draw(sprite,bjorn.x,bjorn.y);
    }
}