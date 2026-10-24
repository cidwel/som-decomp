.setcpu "65816"
.segment "CODE"
.org $4A32
map_control_0d4a32:
    .byte $F1 ; progressive-copy count
    .byte $C6 ; same-value copy count/distance
