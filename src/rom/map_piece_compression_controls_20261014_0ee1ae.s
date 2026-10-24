.setcpu "65816"
.segment "CODE"
.org $E1AE
map_control_0ee1ae:
    .byte $C9 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
