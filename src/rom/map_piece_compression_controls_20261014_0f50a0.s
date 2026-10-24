.setcpu "65816"
.segment "CODE"
.org $50A0
map_control_0f50a0:
    .byte $D5 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
