.setcpu "65816"
.segment "CODE"
.org $E3F2
map_control_0ee3f2:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $C3 ; same-value copy count/distance
