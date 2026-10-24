.setcpu "65816"
.segment "CODE"
.org $4300
map_control_0f4300:
    .byte $CB ; same-value copy count/distance
    .byte $F2 ; progressive-copy count
    .byte $D9 ; same-value copy count/distance
