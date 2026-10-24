.setcpu "65816"
.segment "CODE"
.org $45DE
map_control_0e45de:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
