.setcpu "65816"
.segment "CODE"
.org $3AC7
map_control_0e3ac7:
    .byte $F1 ; progressive-copy count
    .byte $C2 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
