.setcpu "65816"
.segment "CODE"
.org $AF21
map_control_0faf21:
    .byte $C3 ; same-value copy count/distance
    .byte $E5 ; previous-row copy count
