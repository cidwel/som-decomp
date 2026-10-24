.setcpu "65816"
.segment "CODE"
.org $70AC
map_control_0f70ac:
    .byte $D9 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
