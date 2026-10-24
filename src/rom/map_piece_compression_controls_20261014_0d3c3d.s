.setcpu "65816"
.segment "CODE"
.org $3C3D
map_control_0d3c3d:
    .byte $E0 ; previous-row copy escape
    .byte $90 ; row-distance/count
