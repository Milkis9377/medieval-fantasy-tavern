# 🏰 中世紀幻想酒館

A C++ console-based medieval fantasy tavern management game.

這是一個使用 **C++** 開發的文字型中世紀幻想酒館經營遊戲，同時也是我的 C++ 學習專案。

玩家將經營一間酒館，招待不同種族的顧客、販售飲料並賺取金幣，逐步擴充酒館的飲料與製作系統。

---

## 🎮 遊戲介紹

玩家扮演一名酒館經營者。

每天會有不同種族的顧客來到酒館，玩家需要：

- 招待顧客
- 為顧客提供飲料
- 賺取金幣
- 管理飲料庫存
- 製作飲料
- 完成每日營業目標

目前遊戲以 **Console（終端機）** 作為主要操作介面。

---

## 📌 目前版本

**V0.1.0 — Core Gameplay**

目前已完成基本的酒館經營遊戲循環。

### 已完成

- [x] 酒館基本初始化
- [x] 顧客系統
- [x] 不同種族顧客
  - Human
  - Elf
  - Dwarf
- [x] 顧客對話
- [x] 顧客隨機選擇飲料
- [x] 飲料庫存管理
- [x] 顧客金錢管理
- [x] 飲料販售與金錢交易
- [x] 酒館金幣管理
- [x] 每日顧客數量
- [x] 每日收益統計
- [x] 天數系統
- [x] 基本飲料製作功能
- [x] Git / GitHub 版本管理

---

## 🥤 目前飲料

目前遊戲中包含：

| 飲料 | 價格 | 初始庫存 |
|---|---:|---:|
| Beer | 5 | 10 |
| Water | 1 | 10 |
| Apple Juice | 10 | 0 |

部分飲料與製作系統目前仍在開發中。

---

## 🛠️ 使用技術

本專案主要使用：

- **C++**
- Object-Oriented Programming (OOP)
- Class / Object
- Inheritance
- Polymorphism
- `virtual` / `override`
- Pointer / Reference
- STL
  - `vector`
  - `set`
- Git
- GitHub

---

## 🏗️ 專案架構

目前主要類別包含：

```text
Tavern
├── Drink
├── Ingredient
├── Recipe
└── Production

Customer
├── HumanCustomer
├── ElfCustomer
└── DwarfCustomer
```

透過繼承與多型，讓不同種類的顧客可以擁有不同的行為。

例如：

```cpp
Customer* customer = nullptr;

customer = new HumanCustomer();
```

程式可以透過 `Customer` 基底類別的指標操作不同的顧客類型。

---

## 🚧 開發中 / 未來規劃

目前正在逐步完善酒館的製作系統。

預計加入：

- [ ] 完整飲料製作流程
- [ ] 材料消耗
- [ ] Recipe 配方系統
- [ ] 飲料釀造時間
- [ ] 生產佇列
- [ ] 飲料完成與領取
- [ ] 飲料解鎖系統
- [ ] 更多飲料種類
- [ ] 更多顧客與種族
- [ ] 隨機事件
- [ ] 酒館升級系統

功能會隨著開發進度逐步增加。

---

## 📚 開發目的

這個專案除了遊戲本身，也作為我的 C++ 學習專案。

透過實際開發遊戲系統，練習：

- C++ 基礎語法
- 物件導向程式設計
- 繼承與多型
- Pointer / Reference
- STL
- Class 設計
- 模組化程式設計
- Git / GitHub 版本控制
- 遊戲邏輯與系統設計

相比單純練習題，希望透過持續開發一個完整的小型專案，加深對 C++ 的理解。

---

## 📈 Development Progress

### V0.1.0 — Core Gameplay
- 基本酒館系統
- 顧客系統
- 飲料販售
- 金錢與庫存
- 每日營業系統
- 基本飲料製作入口

### V0.1.1 — Brewing System
> In Development

預計完善材料、配方、製作時間與生產流程。

---

## 📄 License

This project is currently developed as a personal learning project.
