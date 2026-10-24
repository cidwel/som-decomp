.setcpu "65816"
.segment "CODE"
.org $D621
map_control_0fd621:
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
