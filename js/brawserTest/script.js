const player = {
    name: document.getElementById("playerName"),
    health: document.getElementById("playerHealth"),
    attackDamage: document.getElementById("playerAttackDamage"),
}
const monster = {
    name: document.getElementById("monsterName"),
    health: document.getElementById("monsterHealth"),
    attackDamage: document.getElementById("monsterAttackDamage"),
}
const history = document.getElementById("history")
const buttons = {
    attack: document.getElementById("attack"),
    doge: document.getElementById("doge"),
    heal: document.getElementById("heal")
}

const monsters = [
    ["Golblin", 50, 10],
    ["Orc", 80, 15],
    ["Dragon", 120, 20]
]

class Entity {
    constructor(name, health, attackDamage) {
        this.name = name
        this.health = health
        this.attackDamage = attackDamage
    }
    takeDamage(from) {
        history.innerHTML += `<div>${from.name} gave ${from.attackDamage} damage to ${this.name}</div>`
        this.health -= from.attackDamage
        if(this.health <= 0) return 0
        return 1
    }
}

class Player extends Entity {
    constructor(name, health, attackDamage) {
        super(name, health, attackDamage)
        this.monster = new Monster(monsters[0][0], monsters[0][1], monsters[0][2])
        this.monsterIndex = 0
        player.name.innerText = this.name
        player.health.innerText = this.health
        player.attackDamage.innerText = this.attackDamage
        this.status = 2
    }
    attack() {
        if(!this.seeStatus()) return
        history.innerHTML = ""
        if(!this.monster.takeDamage(this)) return this.nextMonster()
        monster.health.innerText = this.monster.health
        if(!this.takeDamage(this.monster)) return this.lost()
        player.health.innerText = this.health
    }
    doge() {
        if(!this.seeStatus()) return
        history.innerHTML = ""
        if(Math.floor(Math.random() * 2)) {
            history.innerHTML += "You doged"
        } else {
            if(!this.takeDamage(this.monster)) return this.lost()
            player.health.innerText = this.health
        }
    }
    heal() {
        if(!this.seeStatus()) return
        history.innerHTML = ""
        this.health += 25
        if(this.health > 100) this.health = 100
        if (!this.takeDamage(this.monster)) return this.lost()
        player.health.innerText = this.health
    }
    nextMonster() {
        history.innerHTML += `<div>${this.name} defeated ${this.monster.name}</div>`
        monster.health.innerText = this.monster.health
        if(this.monsterIndex >= monsters.length-1) {
            this.won()
            this.status = 0
            return
        }
        this.monsterIndex++
        this.monster = new Monster(monsters[this.monsterIndex][0], monsters[this.monsterIndex][1], monsters[this.monsterIndex][2])
    }
    lost() {
        history.innerHTML = ""
        player.health.innerText = 0
        history.innerHTML += `<div>You lost</div>`
        this.status = 1
        return 0
    }
    won() {
        history.innerHTML = ""
        history.innerHTML += `<div>You won.</div>`
        this.status = 0
        return 0
    }
    seeStatus() {
        if(this.status == 2) return 1 
        if(this.status == 1) return this.lost()
        if(this.status == 0) return this.won()
    }
}

class Monster extends Entity {
    constructor(name, health, attackDamage) {
        super(name, health, attackDamage)
        monster.name.innerText = this.name
        monster.health.innerText = this.health
        monster.attackDamage.innerText = this.attackDamage
    }
}

const ePlayer = new Player("player", 100, 20)

buttons.attack.addEventListener("click", () => ePlayer.attack())
buttons.doge.addEventListener("click", () => ePlayer.doge())
buttons.heal.addEventListener("click", () => ePlayer.heal())