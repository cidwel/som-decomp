.setcpu "65816"
.segment "CODE"
.org $1FFF
map_control_0f1fff:
    .byte $C4 ; same-value copy count/distance
