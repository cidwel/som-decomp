.setcpu "65816"
.segment "CODE"
.org $DEEF
map_control_0fdeef:
    .byte $D9 ; same-value copy count/distance
