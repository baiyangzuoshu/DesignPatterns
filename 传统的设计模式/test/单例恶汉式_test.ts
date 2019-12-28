import  {HungerSingleton}  from '../单例恶汉式';

let hs=HungerSingleton.getInstance();
let hs2=HungerSingleton.getInstance();

console.log(hs==hs2);