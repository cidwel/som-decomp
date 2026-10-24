.setcpu "65816"
.segment "CODE"
.org $8BF9
map_control_0d8bf9:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
    .byte $C4 ; same-value copy count/distance
