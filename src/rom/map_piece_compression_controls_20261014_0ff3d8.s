.setcpu "65816"
.segment "CODE"
.org $F3D8
map_control_0ff3d8:
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $38 ; row-distance/count
