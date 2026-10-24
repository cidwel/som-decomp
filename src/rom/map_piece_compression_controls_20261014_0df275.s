.setcpu "65816"
.segment "CODE"
.org $F275
map_control_0df275:
    .byte $C1 ; same-value copy count/distance
