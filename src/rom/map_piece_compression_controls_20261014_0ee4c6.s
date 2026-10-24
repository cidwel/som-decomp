.setcpu "65816"
.segment "CODE"
.org $E4C6
map_control_0ee4c6:
    .byte $F3 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
    .byte $C6 ; same-value copy count/distance
