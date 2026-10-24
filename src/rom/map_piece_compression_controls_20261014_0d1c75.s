.setcpu "65816"
.segment "CODE"
.org $1C75
map_control_0d1c75:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $22 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
