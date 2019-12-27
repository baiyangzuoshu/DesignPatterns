interface   Fruit{
    sayName():void; 
}

class   NorthBanana implements  Fruit{
    sayName():void{
        console.log('NorthBanana');
    }
}

class   SouthBanana implements  Fruit{
    sayName():void{
        console.log('SouthBanana');
    }
}

class   NorthApple  implements Fruit{
    sayName():void{
        console.log('NorthApple');
    }
}

class   SouthApple  implements Fruit{
    sayName():void{
        console.log('SouthApple');
    }
}

interface   AbstractFactory{
    createApple():Fruit;
    createBanana():Fruit;
}

export  class   NorthFactory    implements  AbstractFactory{
    createApple():Fruit{
        return  new NorthApple();
    }

    createBanana():Fruit{
        return  new NorthBanana();
    }
}

export  class   SouthFactory    implements  AbstractFactory{
    createApple():Fruit{
        return new SouthApple();
    }

    createBanana():Fruit{
        return new SouthBanana();
    }
}