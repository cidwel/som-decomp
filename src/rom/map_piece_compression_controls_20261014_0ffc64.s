.setcpu "65816"
.segment "CODE"
.org $FC64
map_control_0ffc64:
    .byte $C3 ; same-value copy count/distance
