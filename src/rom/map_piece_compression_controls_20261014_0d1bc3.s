.setcpu "65816"
.segment "CODE"
.org $1BC3
map_control_0d1bc3:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
