.setcpu "65816"
.segment "CODE"
.org $B2C9
map_control_0fb2c9:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
