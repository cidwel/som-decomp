.setcpu "65816"
.segment "CODE"
.org $77F3
map_control_0e77f3:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
