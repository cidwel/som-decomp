.setcpu "65816"
.segment "CODE"
.org $E9CA
map_control_0ee9ca:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
