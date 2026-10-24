.setcpu "65816"
.segment "CODE"
.org $E8AD
map_control_0ee8ad:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
    .byte $C3 ; same-value copy count/distance
