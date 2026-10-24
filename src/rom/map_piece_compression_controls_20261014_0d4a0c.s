.setcpu "65816"
.segment "CODE"
.org $4A0C
map_control_0d4a0c:
    .byte $CA ; same-value copy count/distance
    .byte $DD ; same-value copy count/distance
