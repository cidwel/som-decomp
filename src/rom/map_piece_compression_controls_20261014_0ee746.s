.setcpu "65816"
.segment "CODE"
.org $E746
map_control_0ee746:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
