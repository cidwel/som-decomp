.setcpu "65816"
.segment "CODE"
.org $E490
map_control_0ee490:
    .byte $F3 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
