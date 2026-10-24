.setcpu "65816"
.segment "CODE"
.org $E8E7
map_control_0ee8e7:
    .byte $C5 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $9A ; row-distance/count
