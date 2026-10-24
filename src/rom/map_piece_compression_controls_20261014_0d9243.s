.setcpu "65816"
.segment "CODE"
.org $9243
map_control_0d9243:
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
