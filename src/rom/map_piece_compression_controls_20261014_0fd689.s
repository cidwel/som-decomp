.setcpu "65816"
.segment "CODE"
.org $D689
map_control_0fd689:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $99 ; row-distance/count
    .byte $E3 ; previous-row copy count
