.setcpu "65816"
.segment "CODE"
.org $3ACD
map_control_0f3acd:
    .byte $C1 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
