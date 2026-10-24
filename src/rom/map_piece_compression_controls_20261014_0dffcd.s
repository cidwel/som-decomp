.setcpu "65816"
.segment "CODE"
.org $FFCD
map_control_0dffcd:
    .byte $E2 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
