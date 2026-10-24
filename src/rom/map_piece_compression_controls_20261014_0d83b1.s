.setcpu "65816"
.segment "CODE"
.org $83B1
map_control_0d83b1:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
