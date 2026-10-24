.setcpu "65816"
.segment "CODE"
.org $4028
map_control_0f4028:
    .byte $CA ; same-value copy count/distance
