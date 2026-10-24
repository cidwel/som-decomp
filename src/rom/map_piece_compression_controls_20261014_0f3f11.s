.setcpu "65816"
.segment "CODE"
.org $3F11
map_control_0f3f11:
    .byte $D5 ; same-value copy count/distance
