import  {Bjorn}  from './Bjorn';
class   Sprite{}
class   Graphics{
    draw(sprite:Sprite,x:number,y:number):void{}
}

export  class   GraphicsComponent{
    spriteStand_:Sprite=new Sprite;
    spriteLeft_:Sprite=new Sprite;
    spriteRight_:Sprite=new Sprite;

    update(bjorn:Bjorn,graphics:Graphics):void{
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