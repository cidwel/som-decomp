.setcpu "65816"
.segment "CODE"
.org $DA9F
map_control_0dda9f:
    .byte $E0 ; previous-row copy escape
    .byte $9C ; row-distance/count
    .byte $C7 ; same-value copy count/distance
