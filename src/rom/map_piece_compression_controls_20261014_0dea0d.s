.setcpu "65816"
.segment "CODE"
.org $EA0D
map_control_0dea0d:
    .byte $C1 ; same-value copy count/distance
    .byte $DC ; same-value copy count/distance
