.setcpu "65816"
.segment "CODE"
.org $8567
map_control_0f8567:
    .byte $F1 ; progressive-copy count
    .byte $D9 ; same-value copy count/distance
