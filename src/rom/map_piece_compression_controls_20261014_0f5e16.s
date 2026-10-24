.setcpu "65816"
.segment "CODE"
.org $5E16
map_control_0f5e16:
    .byte $C1 ; same-value copy count/distance
    .byte $D9 ; same-value copy count/distance
