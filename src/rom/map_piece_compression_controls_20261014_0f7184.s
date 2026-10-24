.setcpu "65816"
.segment "CODE"
.org $7184
map_control_0f7184:
    .byte $C6 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
