.setcpu "65816"
.segment "CODE"
.org $8403
map_control_0c8403:
    .byte $F2 ; progressive-copy count
    .byte $C2 ; same-value copy count/distance
