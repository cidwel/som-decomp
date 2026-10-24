.setcpu "65816"
.segment "CODE"
.org $E134
map_control_0fe134:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $22 ; row-distance/count
