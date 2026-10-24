.setcpu "65816"
.segment "CODE"
.org $8AD1
map_control_0e8ad1:
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
