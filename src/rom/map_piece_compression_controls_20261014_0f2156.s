.setcpu "65816"
.segment "CODE"
.org $2156
map_control_0f2156:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
