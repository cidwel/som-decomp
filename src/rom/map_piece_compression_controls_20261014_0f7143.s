.setcpu "65816"
.segment "CODE"
.org $7143
map_control_0f7143:
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
