.setcpu "65816"
.segment "CODE"
.org $8FDE
map_control_0f8fde:
    .byte $D7 ; same-value copy count/distance
    .byte $C7 ; same-value copy count/distance
