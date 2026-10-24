.setcpu "65816"
.segment "CODE"
.org $FACF
map_control_0dfacf:
    .byte $D1 ; same-value copy count/distance
