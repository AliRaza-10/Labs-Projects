
class BorrowRecord:
    def __init__(self,borrowed_by,borrowing_date,returning_date,fine,fine_status):
        self.__borrowed_by = borrowed_by
        self.__borrowing_date = borrowing_date
        self.__returning_date = returning_date
        self.__fine = fine
        self.__fine_status = fine_status
    @property
    def borrowed_by(self):
        return self.__borrowed_by
    @property
    def borrowing_date(self):
        return self.__borrowing_date
    @property
    def returning_date(self):
        return self.__returning_date
    @property
    def fine(self):
        return self.__fine
    @property
    def fine_status(self):
        return self.__fine_status
    @borrowed_by.setter
    def borrowed_by(self,b):
        self.__borrowed_by = b
    @borrowing_date.setter
    def borrowing_date(self,bd):
        self.__borrowing_date = bd
    @returning_date.setter
    def returning_date(self,rd):
        self.__returning_date = rd
    @fine.setter
    def fine(self,f):
        self.__fine = f
    @fine_status.setter
    def fine_status(self,fs):
        self.__fine_status = fs