.setcpu "65816"
.segment "CODE"
.org $E011
map_control_0ee011:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $A5 ; row-distance/count
