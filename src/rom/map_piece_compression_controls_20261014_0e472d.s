.setcpu "65816"
.segment "CODE"
.org $472D
map_control_0e472d:
    .byte $F1 ; progressive-copy count
    .byte $C1 ; same-value copy count/distance
