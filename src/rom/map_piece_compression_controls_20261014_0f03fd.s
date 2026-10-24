.setcpu "65816"
.segment "CODE"
.org $03FD
map_control_0f03fd:
    .byte $C1 ; same-value copy count/distance
