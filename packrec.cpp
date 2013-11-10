/*
ID:wo__che1
PROG: packrec
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;

int n = 0;

typedef struct 
{
	int height;      //long
	int width;      //short
	int area;
} rectangle, *p_rectangel;

int max3(int a, int b, int c)
{
	int max;
	max = a>b?a:b;
	return max>c?max:c;
}

void sideEx(p_rectangel p_r)
{
	int temp;
	temp = p_r->height;
	p_r->height = p_r->width;
	p_r->width = temp;
	return;
}

void rectEx(p_rectangel p_r1, p_rectangel p_r2)
{
	rectangle temp;
	temp.height = p_r1->height;
	temp.width= p_r1->width;

	p_r1->height = p_r2->height;
	p_r1->width= p_r2->width;

	p_r2->height = temp.height;
	p_r2->width= temp.width;
	return;
}

void calcAreaPerm(p_rectangel p_r, int k, int m, rectangle *minArea,
										int (*getArea[5])(rectangle *, int *, int *))
{
	int Area, Height, Width;
	int i;

	if(k == m)
	{
		for(i=0; i<=4; i++)//calculate area of each module
		{
			Area = getArea[i](p_r, &Width, &Height);
			if(Area==minArea[0].area)
			{
				minArea[n].width = Width;
				minArea[n].height = Height;
				minArea[n].area = Area;
				n++;
			}
			else if(Area < minArea[0].area)
			{
				minArea[0].area = Area;
				minArea[0].width = Width;
				minArea[0].height = Height;
				n = 1;
			}				
		}
	}
	else
	{
		for(i=k; i<=m; i++)
		{
			rectEx(&p_r[i], &p_r[k]);
			calcAreaPerm(p_r, k+1, m, minArea, getArea);
			rectEx(&p_r[i], &p_r[k]);
		}
	}
	return;
}

void sideExPerm(p_rectangel p_r, int k, int m, rectangle *minArea,
									int (*getArea[5])(rectangle *, int *, int *))
{
	int i=0;
	if(k>m)
	{
		calcAreaPerm(p_r, 0, 3, minArea, getArea);
	}
	else
	{
		sideExPerm(p_r, k+1, m, minArea, getArea);
		sideEx(&p_r[k]);
		sideExPerm(p_r, k+1, m, minArea, getArea);
	}
	return;
}

int getArea0(rectangle *r, int *b_out, int *h_out)
{
	int bottom = 0, height = 0, i, Area;
	for(i=0; i<4; i++)
	{
		bottom += r[i].width;
		if(r[i].height> height) height = r[i].height;
	}
	*b_out = bottom;
	*h_out = height;
	Area = bottom*height;
	return Area;
}

int getArea1(rectangle *r, int *b_out, int *h_out)
{
    int bottom, height, Area;
	bottom = r[0].width + r[1].width + r[2].width;
	bottom = bottom>r[3].width?bottom:r[3].width;
	height = max3(r[0].height, r[1].height, r[2].height);
	height += r[3].height;
	*b_out = bottom;
	*h_out = height;
	Area = bottom*height;
	return Area;
}

int getArea2(rectangle *r, int *b_out, int *h_out)
{
	int bottom, height, b1, b2, h, Area;
	b1 = r[0].width + r[1].width + r[2].width;
	b2 = r[3].width + r[2].width;
	bottom = b1>b2?b1:b2;
	h = r[0].height>r[1].height?r[0].height:r[1].height;
	h = h + r[3].height;
	height = h>r[2].height?h:r[2].height;
	*b_out = bottom;
	*h_out = height;
	Area = bottom*height;
	return Area;
}

int getArea3(rectangle *r, int *b_out, int *h_out)
{
	int bottom, height, h, b, Area;
	h = r[0].height+r[1].height;
	height = max3(h, r[2].height, r[3].height);
	b = r[0].width>r[1].width?r[0].width:r[1].width;
	bottom = b+r[2].width+r[3].width;
	*b_out = bottom;
	*h_out = height;
	Area = bottom*height;
	return Area;
}

int getArea4(rectangle *r, int *b_out, int *h_out)
{
	int bottom, height, h1, h2, b, b1, b2, h, Area;
	b = r[3].width+r[2].width;
	if(r[0].width<=r[2].width)
	{
		if((r[1].width<=r[3].width)
			||(r[2].height<r[3].height&&r[0].width+r[1].width<=b)) 
		{
			bottom = b;
			h1 = r[0].height+r[2].height;
			h2 = r[1].height+r[3].height;
			height = h1>h2?h1:h2;
			*b_out = bottom;
			*h_out = height;
			Area = bottom*height;
			return Area;
		}
	}

	{
		b1 = r[0].width+r[1].width;
		b2 = r[2].width+r[3].width;
		b = b1>b2?b1:b2;
		b1 = r[0].width+r[3].width;
		b2 = r[2].width+r[1].width;
		b1 = b1>b2?b1:b2;
		b = b>b1?b:b1;
		h1 = r[0].height+r[2].height;
		h2 = r[1].height+r[3].height;
		h = h1>h2?h1:h2;
		*b_out = b;
		*h_out = h;
		Area = b*h;
		return Area;
	}
}

void sortArea(p_rectangel minArea, int m)
{
	int i, j;
	for(i=0; i<m; i++)
		for(j=m-1; j>i; j--)
		{
			if(minArea[j].width<minArea[j-1].width)
			{
				rectEx(&minArea[j], &minArea[j-1]);
			}
		}
}

int main() 
{
    ofstream fout ("packrec.out");
    ifstream fin ("packrec.in");
    int i, a, b, area, height, width;
	rectangle r[4], *minArea;
	int (*getArea[5])(rectangle *, int *, int *);

	getArea[0] = getArea0; 
	getArea[1] = getArea1;  
	getArea[2] = getArea2;
	getArea[3] = getArea3;
	getArea[4] = getArea4;

	minArea = (p_rectangel)new rectangle[1000];
	for(i=0; i<4; i++)
    {
    	fin >> a >> b;
		r[i].height = a>b? a:b;
		r[i].width = a>b? b:a;
	}
		
	area = getArea0(r, &width, &height);
	minArea[0].area = area;
	minArea[0].height = height;
	minArea[0].width = width; //init
	n = 1;
	sideExPerm(r, 0, 3, minArea, getArea);
	//calcAreaPerm(r, 0, 3, minArea, getArea);

	fout <<minArea[0].area <<endl;
	
	for(i=0; i<n; i++)
	{
		if(minArea[i].width>minArea[i].height) 
		{
			int temp;
			temp = minArea[i].width;
			minArea[i].width = minArea[i].height;
			minArea[i].height = temp;
		}
	}
	sortArea(minArea, n);
	fout <<minArea[0].width << " "<<minArea[0].height <<endl;
	for(i=1; i<n; i++)
	{
		if(minArea[i].width>minArea[i-1].width)
		fout <<minArea[i].width << " "<<minArea[i].height <<endl;
	}

    return 0;
}
