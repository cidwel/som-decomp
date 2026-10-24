.setcpu "65816"
.segment "CODE"
.org $8AD3
map_control_0f8ad3:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $2B ; row-distance/count
