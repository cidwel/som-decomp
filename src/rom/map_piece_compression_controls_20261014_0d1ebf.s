.setcpu "65816"
.segment "CODE"
.org $1EBF
map_control_0d1ebf:
    .byte $C1 ; same-value copy count/distance
    .byte $E4 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
