.setcpu "65816"
.segment "CODE"
.org $D28B
map_control_0fd28b:
    .byte $E1 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
