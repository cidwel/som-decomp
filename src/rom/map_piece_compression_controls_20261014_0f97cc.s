.setcpu "65816"
.segment "CODE"
.org $97CC
map_control_0f97cc:
    .byte $C2 ; same-value copy count/distance
