.setcpu "65816"
.segment "CODE"
.org $FBC0
map_control_0ffbc0:
    .byte $C1 ; same-value copy count/distance
