# Engine - Codename Springhawl

## Structure
### Gameobject
This gameobject is the parent of every other object within the current scene

```c++
class Gameobject{
public:
  Gameobject();
  //Interactions
  void start(); //Called on construction
  void update();
  void onDestory();

  //Collision
  void onCollision();

  //....

  //Vars
  Vec2 position;
  int rotation;
}
```

Example use
```c++
class Player : Gameobject{

  
  int hp;
  void start(){
      hp = 100;
  }
  
  void update(){
    if(Input.Key == W){
        position.x++;
    }

}

}
```

## Raycasting

```c++
public void rayCast(){


}
```

