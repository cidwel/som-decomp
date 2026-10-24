.setcpu "65816"
.segment "CODE"
.org $1EA0
map_control_0e1ea0:
    .byte $E5 ; previous-row copy count
    .byte $C5 ; same-value copy count/distance
    .byte $E6 ; previous-row copy count
