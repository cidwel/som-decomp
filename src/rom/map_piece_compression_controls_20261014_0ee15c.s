.setcpu "65816"
.segment "CODE"
.org $E15C
map_control_0ee15c:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
