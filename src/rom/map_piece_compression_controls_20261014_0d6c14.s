.setcpu "65816"
.segment "CODE"
.org $6C14
map_control_0d6c14:
    .byte $F1 ; progressive-copy count
    .byte $C4 ; same-value copy count/distance
