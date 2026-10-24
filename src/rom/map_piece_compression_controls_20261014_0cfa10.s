.setcpu "65816"
.segment "CODE"
.org $FA10
map_control_0cfa10:
    .byte $C2 ; same-value copy count/distance
