.setcpu "65816"
.segment "CODE"
.org $8088
map_control_0d8088:
    .byte $D9 ; same-value copy count/distance
