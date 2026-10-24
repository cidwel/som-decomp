.setcpu "65816"
.segment "CODE"
.org $1BAD
map_control_0d1bad:
    .byte $E1 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
