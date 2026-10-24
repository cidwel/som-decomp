.setcpu "65816"
.segment "CODE"
.org $0F11
map_control_0f0f11:
    .byte $C1 ; same-value copy count/distance
    .byte $D9 ; same-value copy count/distance
