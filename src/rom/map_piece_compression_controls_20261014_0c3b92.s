.setcpu "65816"
.segment "CODE"
.org $3B92
map_control_0c3b92:
    .byte $D7 ; same-value copy count/distance
    .byte $E5 ; previous-row copy count
