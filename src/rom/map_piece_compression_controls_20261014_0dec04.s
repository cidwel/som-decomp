.setcpu "65816"
.segment "CODE"
.org $EC04
map_control_0dec04:
    .byte $D5 ; same-value copy count/distance
