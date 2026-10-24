.setcpu "65816"
.segment "CODE"
.org $2C64
map_control_0f2c64:
    .byte $C1 ; same-value copy count/distance
    .byte $DF ; same-value copy count/distance
    .byte $C2 ; same-value copy count/distance
