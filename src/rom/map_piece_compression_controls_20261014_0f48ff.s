.setcpu "65816"
.segment "CODE"
.org $48FF
map_control_0f48ff:
    .byte $C1 ; same-value copy count/distance
