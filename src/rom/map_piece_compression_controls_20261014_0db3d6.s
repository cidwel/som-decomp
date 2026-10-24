.setcpu "65816"
.segment "CODE"
.org $B3D6
map_control_0db3d6:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
