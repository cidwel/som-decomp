.setcpu "65816"
.segment "CODE"
.org $F874
map_control_0ef874:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
