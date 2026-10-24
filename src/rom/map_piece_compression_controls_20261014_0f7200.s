.setcpu "65816"
.segment "CODE"
.org $7200
map_control_0f7200:
    .byte $C5 ; same-value copy count/distance
