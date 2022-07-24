import unittest
from line import Line


class Testline (unittest.TestCase):


    def test_distance_between_same_points(self):
        line=Line(0,0,0,0)
        assert line.len()==0
    def test_distance_between_same_points(self):
        line=Line(1,0,0,0)
        assert line.len()==0
