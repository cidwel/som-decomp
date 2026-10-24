.setcpu "65816"
.segment "CODE"
.org $62C8
map_control_0d62c8:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
    .byte $C3 ; same-value copy count/distance
