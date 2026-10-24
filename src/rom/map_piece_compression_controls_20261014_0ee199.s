.setcpu "65816"
.segment "CODE"
.org $E199
map_control_0ee199:
    .byte $E0 ; previous-row copy escape
    .byte $95 ; row-distance/count
    .byte $E1 ; previous-row copy count
