.setcpu "65816"
.segment "CODE"
.org $50BD
map_control_0e50bd:
    .byte $F1 ; progressive-copy count
    .byte $C2 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
