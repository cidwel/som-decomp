.setcpu "65816"
.segment "CODE"
.org $5BC3
map_control_0f5bc3:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
