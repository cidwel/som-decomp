.setcpu "65816"
.segment "CODE"
.org $F80A
map_control_0df80a:
    .byte $C4 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
