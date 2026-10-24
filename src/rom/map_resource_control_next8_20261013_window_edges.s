; Original overlay window controls; no adjacent graphics.
.setcpu "65816"
.segment "CODE"
.org $0342
map_resource_control_next8_20261013_window_edges:
.macro overlay_window_edges left, right
    .byte left, right
.endmacro
    overlay_window_edges 255, 0 ; repeated line 0
    overlay_window_edges 255, 0 ; repeated line 1
    overlay_window_edges 255, 0 ; repeated line 2
    overlay_window_edges 255, 0 ; repeated line 3
    overlay_window_edges 0, 255 ; repeated line 4
    overlay_window_edges 0, 255 ; repeated line 5
    overlay_window_edges 0, 255 ; repeated line 6
    overlay_window_edges 0, 255 ; repeated line 7
    overlay_window_edges 0, 255 ; repeated line 8
    overlay_window_edges 0, 255 ; repeated line 9
    overlay_window_edges 0, 255 ; repeated line 10
    overlay_window_edges 0, 255 ; repeated line 11
    overlay_window_edges 0, 255 ; repeated line 12
    overlay_window_edges 0, 255 ; repeated line 13
    overlay_window_edges 0, 255 ; repeated line 14
    overlay_window_edges 0, 255 ; repeated line 15
    overlay_window_edges 0, 255 ; repeated line 16
    overlay_window_edges 0, 255 ; repeated line 17
    overlay_window_edges 0, 255 ; repeated line 18
    overlay_window_edges 0, 255 ; repeated line 19
    overlay_window_edges 0, 255 ; repeated line 20
    overlay_window_edges 0, 255 ; repeated line 21
    overlay_window_edges 0, 255 ; repeated line 22
    overlay_window_edges 0, 255 ; repeated line 23
    overlay_window_edges 255, 0 ; repeated line 24
    overlay_window_edges 255, 0 ; repeated line 25
    overlay_window_edges 255, 0 ; repeated line 26
    overlay_window_edges 255, 0 ; repeated line 27
    overlay_window_edges 255, 0 ; repeated line 28
    overlay_window_edges 255, 0 ; repeated line 29
    overlay_window_edges 255, 0 ; repeated line 30
