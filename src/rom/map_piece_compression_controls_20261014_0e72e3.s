.setcpu "65816"
.segment "CODE"
.org $72E3
map_control_0e72e3:
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
