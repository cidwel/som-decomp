.setcpu "65816"
.segment "CODE"
.org $85CC
map_control_0f85cc:
    .byte $C1 ; same-value copy count/distance
