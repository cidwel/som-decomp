.setcpu "65816"
.segment "CODE"
.org $2038
map_control_0e2038:
    .byte $C5 ; same-value copy count/distance
    .byte $E5 ; previous-row copy count
