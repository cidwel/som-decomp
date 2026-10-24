.setcpu "65816"
.segment "CODE"
.org $F893
map_control_0ef893:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
