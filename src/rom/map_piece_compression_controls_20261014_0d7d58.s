.setcpu "65816"
.segment "CODE"
.org $7D58
map_control_0d7d58:
    .byte $F1 ; progressive-copy count
    .byte $C2 ; same-value copy count/distance
