.setcpu "65816"
.segment "CODE"
.org $E9D1
map_control_0ee9d1:
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
