.setcpu "65816"
.segment "CODE"
.org $3F80
map_control_0f3f80:
    .byte $CA ; same-value copy count/distance
