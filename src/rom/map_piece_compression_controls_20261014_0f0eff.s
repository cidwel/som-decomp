.setcpu "65816"
.segment "CODE"
.org $0EFF
map_control_0f0eff:
    .byte $C3 ; same-value copy count/distance
