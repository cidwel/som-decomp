.setcpu "65816"
.segment "CODE"
.org $5149
map_control_0d5149:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
