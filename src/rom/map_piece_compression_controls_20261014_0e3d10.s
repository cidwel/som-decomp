.setcpu "65816"
.segment "CODE"
.org $3D10
map_control_0e3d10:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
