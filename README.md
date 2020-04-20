# Projection-Model
Graphics ( parallel and perspective projection) 

#---------------------------------------------------------------------
To Compile:
$ gcc -o hmwk_02 hmwk_02.c face.c model.c projection.c triangle.c vertex.c view.c -lm
$ ./hmwk_02 Tests/pyramid.svfm Tests/pyramid_setting_01.view



#----------------------------------------------------------------------
Background:

  * The fundamental mathematics of projection (parallel and
    perspective) are described in the two handouts
    "4303 Projection Parallel" and "4303 Projections"
    available on Canvas.

  * View files have the following format.  (The basic structure is
    the same as the SVFM file, just with different entries.)

    - Blank lines are to be ignored.  (A blank line has no
      characters at all or is just whitespace.)

    - Lines with '#' as the first non-whitespace character are
      comments and are to be ignored.

    - A line with a 'w' as the first non-whitespace character is
      the Worldspace line.  There will be four numbers following
      the 'w': the xMin, yMin, xMax, and yMax limits of the
      desired worldspace.  The 'w' and the limits will be
      separated by whitespace.  Example:

        w  1.1 2.2  16.5   23.3

    - A line with a 'c' as the first non-whitespace character is
      the Canvas size line.  There will be two integers following
      the 'c': the width and the height of the canvas.  The 'c'
      and the width and height will be separated by whitespace.
      Example:

        c   500  400

    - A line with an 's' as the first non-whitespace character is
      the usable Screenspace line.  There will be four numbers
      following the 's': the xMin, yMin, xMax, and yMax limits of
      the desired viewport.  The 's' and the limits will be
      separated by whitespace.  Example:

        s   0.10    0.15  0.80   0.75

    - A line with a 'd' as the first non-whitespace character is
      the viewpoint Distance line.  There will be a number
      following the 'd': the position of the viewpoint on the z
      axis.  The 'd' and the viewpoint position will be separated
      by whitespace.  Example:

        d  12.9

      If the d is zero (or omitted entirely), the view represents
      a PARALLEL projection.  (If the d is non-zero, the view
      represents a PERSPECTIVE projection, with the viewpoint
      located at [ 0, 0, d ]T.)

    - If a line starts with any other non-whitespace character, it
      should be silently ignored.  ('silently' means you should
      not print an error message.  Just ignore it.)

