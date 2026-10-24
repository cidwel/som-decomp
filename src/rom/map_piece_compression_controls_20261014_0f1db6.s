.setcpu "65816"
.segment "CODE"
.org $1DB6
map_control_0f1db6:
    .byte $E1 ; previous-row copy count
    .byte $C4 ; same-value copy count/distance
