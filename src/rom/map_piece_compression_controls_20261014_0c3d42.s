.setcpu "65816"
.segment "CODE"
.org $3D42
map_control_0c3d42:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
