.setcpu "65816"
.segment "CODE"
.org $3D06
map_control_0e3d06:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
