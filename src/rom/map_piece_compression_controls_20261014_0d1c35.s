.setcpu "65816"
.segment "CODE"
.org $1C35
map_control_0d1c35:
    .byte $C7 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
    .byte $C3 ; same-value copy count/distance
