.setcpu "65816"
.segment "CODE"
.org $FC3B
map_control_0ffc3b:
    .byte $D1 ; same-value copy count/distance
