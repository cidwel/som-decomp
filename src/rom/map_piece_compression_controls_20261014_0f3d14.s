.setcpu "65816"
.segment "CODE"
.org $3D14
map_control_0f3d14:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
