import  {GraphicsComponent} from './GraphicsComponent';
import  {InputConponent}  from './InputComponent';
import  {PhysicsComponent} from './PhysicsComponent'

export  class   Bjorn{
    velocity:number;
    x:number;
    y:number;
    graphics_:GraphicsComponent=new GraphicsComponent();
    input_:InputConponent=new InputConponent();
    physics_:PhysicsComponent=new PhysicsComponent();

    constructor(velocity:number,x:number,y:number){
        this.velocity=velocity;
        this.x=x;
        this.y=y;
    }


}