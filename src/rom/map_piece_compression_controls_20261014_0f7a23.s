.setcpu "65816"
.segment "CODE"
.org $7A23
map_control_0f7a23:
    .byte $D3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
