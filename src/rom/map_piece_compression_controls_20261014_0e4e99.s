.setcpu "65816"
.segment "CODE"
.org $4E99
map_control_0e4e99:
    .byte $F1 ; progressive-copy count
    .byte $C2 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
