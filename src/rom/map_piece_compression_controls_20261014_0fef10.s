.setcpu "65816"
.segment "CODE"
.org $EF10
map_control_0fef10:
    .byte $C2 ; same-value copy count/distance
