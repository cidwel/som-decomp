.setcpu "65816"
.segment "CODE"
.org $8C92
map_control_0f8c92:
    .byte $D7 ; same-value copy count/distance
    .byte $E4 ; previous-row copy count
