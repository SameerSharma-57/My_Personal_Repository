class Line(object):

    x1=0
    x2=0
    y1=0
    y2=0

    def __init__(self,x1,x2,y1,y2):
        self.x1=x1
        self.x2=x2
        self.y1=y1
        self.y2=y2

    def len(self):
        
        
        x=self.x1-self.x2
        y=self.y1-self.y2
        return ((x**2)+(y**2))**0.5
        


    

        


