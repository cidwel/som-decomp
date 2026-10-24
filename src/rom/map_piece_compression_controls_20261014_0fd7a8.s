.setcpu "65816"
.segment "CODE"
.org $D7A8
map_control_0fd7a8:
    .byte $E5 ; previous-row copy count
    .byte $C5 ; same-value copy count/distance
