.setcpu "65816"
.segment "CODE"
.org $2651
map_control_0d2651:
    .byte $F2 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
