.setcpu "65816"
.segment "CODE"
.org $5A76
map_control_0e5a76:
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
    .byte $DE ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
