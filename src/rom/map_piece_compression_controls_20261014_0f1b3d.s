.setcpu "65816"
.segment "CODE"
.org $1B3D
map_control_0f1b3d:
    .byte $E0 ; previous-row copy escape
    .byte $A3 ; row-distance/count
