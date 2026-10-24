.setcpu "65816"
.segment "CODE"
.org $C408
map_control_0ec408:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $D1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
