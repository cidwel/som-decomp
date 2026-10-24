.setcpu "65816"
.segment "CODE"
.org $0F16
map_control_0e0f16:
    .byte $F1 ; progressive-copy count
    .byte $D9 ; same-value copy count/distance
