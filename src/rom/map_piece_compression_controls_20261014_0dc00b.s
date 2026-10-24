.setcpu "65816"
.segment "CODE"
.org $C00B
map_control_0dc00b:
    .byte $F1 ; progressive-copy count
    .byte $C1 ; same-value copy count/distance
