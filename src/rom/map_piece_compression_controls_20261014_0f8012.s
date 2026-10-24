.setcpu "65816"
.segment "CODE"
.org $8012
map_control_0f8012:
    .byte $C9 ; same-value copy count/distance
