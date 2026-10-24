.setcpu "65816"
.segment "CODE"
.org $06B2
map_control_0f06b2:
    .byte $E0 ; previous-row copy escape
    .byte $2A ; row-distance/count
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $31 ; row-distance/count
