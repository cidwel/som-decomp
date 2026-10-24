.setcpu "65816"
.segment "CODE"
.org $509A
map_control_0e509a:
    .byte $F2 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
