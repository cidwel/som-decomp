.setcpu "65816"
.segment "CODE"
.org $D7A7
map_control_0dd7a7:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
