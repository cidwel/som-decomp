.setcpu "65816"
.segment "CODE"
.org $F27E
map_control_0ff27e:
    .byte $D2 ; same-value copy count/distance
