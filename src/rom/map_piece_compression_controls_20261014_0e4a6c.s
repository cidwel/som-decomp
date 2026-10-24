.setcpu "65816"
.segment "CODE"
.org $4A6C
map_control_0e4a6c:
    .byte $C1 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
