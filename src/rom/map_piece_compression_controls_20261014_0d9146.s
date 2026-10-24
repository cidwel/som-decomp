.setcpu "65816"
.segment "CODE"
.org $9146
map_control_0d9146:
    .byte $F1 ; progressive-copy count
    .byte $D9 ; same-value copy count/distance
