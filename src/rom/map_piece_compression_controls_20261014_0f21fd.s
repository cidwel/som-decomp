.setcpu "65816"
.segment "CODE"
.org $21FD
map_control_0f21fd:
    .byte $C6 ; same-value copy count/distance
