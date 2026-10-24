.setcpu "65816"
.segment "CODE"
.org $E8ED
map_control_0ee8ed:
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
    .byte $D5 ; same-value copy count/distance
