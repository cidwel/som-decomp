.setcpu "65816"
.segment "CODE"
.org $5485
map_control_0f5485:
    .byte $E1 ; previous-row copy count
    .byte $D7 ; same-value copy count/distance
