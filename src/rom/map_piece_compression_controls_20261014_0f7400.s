.setcpu "65816"
.segment "CODE"
.org $7400
map_control_0f7400:
    .byte $C2 ; same-value copy count/distance
