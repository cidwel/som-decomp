.setcpu "65816"
.segment "CODE"
.org $F4CF
map_control_0ff4cf:
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $38 ; row-distance/count
