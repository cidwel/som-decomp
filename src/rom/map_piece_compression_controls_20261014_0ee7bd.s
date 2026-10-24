.setcpu "65816"
.segment "CODE"
.org $E7BD
map_control_0ee7bd:
    .byte $C6 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
