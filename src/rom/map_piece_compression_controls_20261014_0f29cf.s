.setcpu "65816"
.segment "CODE"
.org $29CF
map_control_0f29cf:
    .byte $C5 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
