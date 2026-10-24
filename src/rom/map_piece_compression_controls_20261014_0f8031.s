.setcpu "65816"
.segment "CODE"
.org $8031
map_control_0f8031:
    .byte $C9 ; same-value copy count/distance
