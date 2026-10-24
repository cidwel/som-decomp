.setcpu "65816"
.segment "CODE"
.org $7FB0
map_control_0d7fb0:
    .byte $C9 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
