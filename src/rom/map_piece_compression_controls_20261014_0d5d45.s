.setcpu "65816"
.segment "CODE"
.org $5D45
map_control_0d5d45:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
    .byte $DB ; same-value copy count/distance
