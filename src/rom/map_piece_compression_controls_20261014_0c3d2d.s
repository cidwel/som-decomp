.setcpu "65816"
.segment "CODE"
.org $3D2D
map_control_0c3d2d:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
