.setcpu "65816"
.segment "CODE"
.org $8057
map_control_0f8057:
    .byte $C2 ; same-value copy count/distance
