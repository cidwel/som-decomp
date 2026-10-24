.setcpu "65816"
.segment "CODE"
.org $AEFB
map_control_0faefb:
    .byte $D9 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
