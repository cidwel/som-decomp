.setcpu "65816"
.segment "CODE"
.org $4E70
map_control_0f4e70:
    .byte $C3 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
