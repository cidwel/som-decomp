.setcpu "65816"
.segment "CODE"
.org $E4A8
map_control_0ee4a8:
    .byte $F2 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
