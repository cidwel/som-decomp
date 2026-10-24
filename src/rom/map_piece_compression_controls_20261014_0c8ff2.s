.setcpu "65816"
.segment "CODE"
.org $8FF2
map_control_0c8ff2:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
