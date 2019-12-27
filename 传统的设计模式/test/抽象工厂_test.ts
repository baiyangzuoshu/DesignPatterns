import  {NorthFactory,SouthFactory}  from '../抽象工厂';

let nf=new NorthFactory();
let apple=nf.createApple();
apple.sayName();
let banana=nf.createBanana();
banana.sayName();

let sf=new SouthFactory();
banana=sf.createBanana();
banana.sayName();
apple=sf.createApple();
apple.sayName();