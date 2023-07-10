from typing import Any


Item = dict[str, Any]
Items = list[Item]
ItemsById = dict[int, Item]
ItemsCollection = dict[int, list[Item]]


class TreeStore:

    def __init__(self, items: Items) -> None:
        self.items = items
        self._items_by_id: ItemsById | None = None
        self._parents: ItemsCollection | None = None
        self._childs: ItemsCollection | None = None

    def _get_parents(
        self,
        item_id: int,
        parent_id: int,
        parents: ItemsCollection,
            ) -> ItemsCollection:
        """Получить родителей выбранного item

        Args:
            item_id (int): id элемента
            parent_id (int): id родительского элемента
            parents (ItemsCollection): коллекция родителей по id

        Returns:
            ItemsCollection: коллекция родителей по id
        """
        if isinstance(parent_id, int):
            item = self.items_by_id[parent_id]
            parents[item_id].append(item)
            parents = self._get_parents(item_id, item['parent'], parents)
        return parents

    @property
    def items_by_id(self) -> ItemsById:
        """Items по из id

        Returns:
            ItemsById
        """
        if self._items_by_id is None:
            self._items_by_id = {item['id']: item for item in self.items}
        return self._items_by_id

    @property
    def parents(self) -> ItemsCollection:
        """Все родительские item для каждого id

        Returns:
            ItemsCollection
        """
        if self._parents is None:
            self._parents = {item['id']: [] for item in self.items}
            for v in self.items_by_id.values():
                self._parents = self._get_parents(
                    v['id'], v['parent'], self._parents
                        )
        return self._parents

    @property
    def childs(self) -> ItemsCollection:
        """Все дочерние item для каждого id

        Returns:
            ItemsCollection
        """
        if self._childs is None:
            self._childs = {item['id']: [] for item in self.items}
            for k, v in self.parents.items():
                for item in v:
                    self._childs[item['id']].append(self.items_by_id[k])
        return self._childs

    def getAll(self) -> Items:
        """Должен возвращать изначальный массив элементов

        Returns:
            Items
        """
        return self.items

    def getItem(self, item_id: int) -> Item:
        """Принимает id элемента и возвращает сам объект элемента

        Args:
            item_id (int): id элемента

        Raises:
            KeyError: элемента с item_id нет в массиве

        Returns:
            Item
        """
        return self.items_by_id[item_id]

    def getChildren(self, item_id: int) -> list[Item]:
        """Принимает id элемента и возвращает массив элементов,
        являющихся дочерними для того элемента,
        чей id получен в аргументе. Если у элемента нет дочерних,
        то должен возвращаться пустой массив

        Args:
            item_id (int): id элемента

        Raises:
            KeyError: элемента с item_id нет в массиве

        Returns:
            list[Item]:
        """
        return self.childs[item_id]

    def getAllParents(self, item_id: int):
        """Принимает id элемента и возвращает массив из цепочки
        родительских элементов, начиная от самого элемента, чей id был
        передан в аргументе и до корневого элемента, т.е. должен получиться
        путь элемента наверх дерева через цепочку родителей к корню дерева.
        Порядок элементов важен!

        Args:
            item_id (int): id элемента

        Raises:
            KeyError: элемента с item_id нет в массиве

        Returns:
            list[Item]:
        """
        return self.parents[item_id]


items: Items = [
    {"id": 1, "parent": "root"},
    {"id": 2, "parent": 1, "type": "test"},
    {"id": 3, "parent": 1, "type": "test"},
    {"id": 4, "parent": 2, "type": "test"},
    {"id": 5, "parent": 2, "type": "test"},
    {"id": 6, "parent": 2, "type": "test"},
    {"id": 7, "parent": 4, "type": None},
    {"id": 8, "parent": 4, "type": None},
]
ts = TreeStore(items)


assert ts.getAll() == items
assert ts.getItem(7) == {"id": 7, "parent": 4, "type": None}
try:
    assert ts.getItem(22)
except KeyError:
    pass

assert ts.getChildren(4) == [
    {"id": 7, "parent": 4, "type": None},
    {"id": 8, "parent": 4, "type": None},
        ]
assert ts.getChildren(5) == []

try:
    assert ts.getChildren(22)
except KeyError:
    pass

assert ts.getAllParents(7) == [
    {"id": 4, "parent": 2, "type": "test"},
    {"id": 2, "parent": 1, "type": "test"},
    {"id": 1, "parent": "root"},
    ]
assert ts.getAllParents(1) == []
try:
    assert ts.getAllParents(22)
except KeyError:
    pass
