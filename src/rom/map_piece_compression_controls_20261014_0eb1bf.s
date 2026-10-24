.setcpu "65816"
.segment "CODE"
.org $B1BF
map_control_0eb1bf:
    .byte $E1 ; previous-row copy count
    .byte $D1 ; same-value copy count/distance
