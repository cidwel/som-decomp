.setcpu "65816"
.segment "CODE"
.org $D77C
map_control_0dd77c:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
