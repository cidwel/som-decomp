.setcpu "65816"
.segment "CODE"
.org $F47D
map_control_0ef47d:
    .byte $E0 ; previous-row copy escape
    .byte $B3 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
