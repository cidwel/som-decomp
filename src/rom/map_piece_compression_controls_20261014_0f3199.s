.setcpu "65816"
.segment "CODE"
.org $3199
map_control_0f3199:
    .byte $E1 ; previous-row copy count
    .byte $D2 ; same-value copy count/distance
