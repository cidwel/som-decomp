.setcpu "65816"
.segment "CODE"
.org $0FE8
map_control_0e0fe8:
    .byte $E0 ; previous-row copy escape
    .byte $94 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
