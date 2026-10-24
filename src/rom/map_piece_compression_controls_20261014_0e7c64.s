.setcpu "65816"
.segment "CODE"
.org $7C64
map_control_0e7c64:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
