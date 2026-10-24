.setcpu "65816"
.segment "CODE"
.org $A110
map_control_0fa110:
    .byte $C1 ; same-value copy count/distance
