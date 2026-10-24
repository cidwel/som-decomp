.setcpu "65816"
.segment "CODE"
.org $E768
map_control_0ee768:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $C3 ; same-value copy count/distance
