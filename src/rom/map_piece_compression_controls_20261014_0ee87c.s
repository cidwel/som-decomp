.setcpu "65816"
.segment "CODE"
.org $E87C
map_control_0ee87c:
    .byte $E1 ; previous-row copy count
    .byte $D1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
