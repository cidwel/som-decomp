.setcpu "65816"
.segment "CODE"
.org $203B
map_control_0d203b:
    .byte $F1 ; progressive-copy count
    .byte $C1 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
