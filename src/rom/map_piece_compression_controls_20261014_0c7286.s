.setcpu "65816"
.segment "CODE"
.org $7286
map_control_0c7286:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $C3 ; same-value copy count/distance
