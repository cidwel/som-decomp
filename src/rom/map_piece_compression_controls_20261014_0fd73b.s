.setcpu "65816"
.segment "CODE"
.org $D73B
map_control_0fd73b:
    .byte $D4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
