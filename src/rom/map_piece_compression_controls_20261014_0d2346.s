.setcpu "65816"
.segment "CODE"
.org $2346
map_control_0d2346:
    .byte $E5 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $8B ; row-distance/count
    .byte $C1 ; same-value copy count/distance
