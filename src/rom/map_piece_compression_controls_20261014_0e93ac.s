.setcpu "65816"
.segment "CODE"
.org $93AC
map_control_0e93ac:
    .byte $D6 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
