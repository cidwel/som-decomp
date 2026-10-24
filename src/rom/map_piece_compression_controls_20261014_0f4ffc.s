.setcpu "65816"
.segment "CODE"
.org $4FFC
map_control_0f4ffc:
    .byte $C2 ; same-value copy count/distance
