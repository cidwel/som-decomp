.setcpu "65816"
.segment "CODE"
.org $AA86
map_control_0eaa86:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $E1 ; previous-row copy count
    .byte $D1 ; same-value copy count/distance
