.setcpu "65816"
.segment "CODE"
.org $FEBF
map_control_0dfebf:
    .byte $C9 ; same-value copy count/distance
