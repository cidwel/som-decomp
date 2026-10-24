.setcpu "65816"
.segment "CODE"
.org $E434
map_control_0ee434:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
