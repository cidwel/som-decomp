.setcpu "65816"
.segment "CODE"
.org $1711
map_control_0c1711:
    .byte $F2 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
