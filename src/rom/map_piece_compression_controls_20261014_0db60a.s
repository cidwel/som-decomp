.setcpu "65816"
.segment "CODE"
.org $B60A
map_control_0db60a:
    .byte $C6 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
