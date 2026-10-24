.setcpu "65816"
.segment "CODE"
.org $3EBE
map_control_0e3ebe:
    .byte $E3 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $93 ; row-distance/count
    .byte $E1 ; previous-row copy count
