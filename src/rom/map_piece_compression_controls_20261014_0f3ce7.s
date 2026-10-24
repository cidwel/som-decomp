.setcpu "65816"
.segment "CODE"
.org $3CE7
map_control_0f3ce7:
    .byte $F1 ; progressive-copy count
    .byte $C1 ; same-value copy count/distance
