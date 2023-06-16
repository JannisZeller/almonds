# almonds
Generation of Mandelbrot Sets in C++ (very basic), Python Loops, Numba (`jit` and `jit.cuda`) and PyTorch. The algorithm can be found [here](https://en.wikipedia.org/wiki/Plotting_algorithms_for_the_Mandelbrot_set#Optimized_escape_time_algorithms).

Some interesting regions of the Mandelbrot Set are
| $x$-min | $x$-max | $y$-min | $y$-max | Describtion |
|---------|---------|---------|---------|-------------|
| -2.5    | 1.0     | -1.0    | 1.0     | Full set for 1920p or 3840p |
| -2.0    | 1.3     | -0.2    | 0.2     | Wide central image |
| -0.750222 | -0.749191 | 0.031161 | 0.031752 | Wild swirls |

In case anyone wondering (probably nobody...): "Mandelbrot" is actually a [name](https://de.wikipedia.org/wiki/Beno%C3%AEt_Mandelbrot) but "Mandel" is also the German word for almod...
