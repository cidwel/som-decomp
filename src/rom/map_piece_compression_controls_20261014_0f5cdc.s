.setcpu "65816"
.segment "CODE"
.org $5CDC
map_control_0f5cdc:
    .byte $D7 ; same-value copy count/distance
    .byte $C5 ; same-value copy count/distance
