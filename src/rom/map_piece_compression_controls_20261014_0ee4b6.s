.setcpu "65816"
.segment "CODE"
.org $E4B6
map_control_0ee4b6:
    .byte $F2 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
