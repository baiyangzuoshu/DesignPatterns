import  {Graphics,GraphicsComponent,PlayerGraphicsComponent} from './GraphicsComponent';
import  {InputConponent,PlayerInputConponent}  from './InputComponent';
import  {PhysicsComponent,World,PlayerPhysicsComponent} from './PhysicsComponent'

export  class   GameObject{
    velocity:number;
    x:number;
    y:number;
    graphics_:GraphicsComponent;
    input_:InputConponent;
    physics_:PhysicsComponent;

    constructor(graphics:GraphicsComponent,input:InputConponent,physics:PhysicsComponent,velocity:number=0,x:number=0,y:number=0){
        this.velocity=velocity;
        this.x=x;
        this.y=y;
        this.graphics_=graphics;
        this.input_=input;
        this.physics_=physics;
    }

    update(world:World,graphics:Graphics){
        this.input_.update(this);
        this.graphics_.update(this,graphics);
        this.physics_.update(this,world);
    }

    createBjorn(){
        return  new GameObject(new PlayerGraphicsComponent,new PlayerInputConponent,new PlayerPhysicsComponent);
    }
}