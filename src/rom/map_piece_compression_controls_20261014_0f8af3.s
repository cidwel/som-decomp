.setcpu "65816"
.segment "CODE"
.org $8AF3
map_control_0f8af3:
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $97 ; row-distance/count
