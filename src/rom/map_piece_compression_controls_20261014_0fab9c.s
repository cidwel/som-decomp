.setcpu "65816"
.segment "CODE"
.org $AB9C
map_control_0fab9c:
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $96 ; row-distance/count
