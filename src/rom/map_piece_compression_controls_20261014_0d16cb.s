.setcpu "65816"
.segment "CODE"
.org $16CB
map_control_0d16cb:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $C6 ; same-value copy count/distance
