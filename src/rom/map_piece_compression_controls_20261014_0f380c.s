.setcpu "65816"
.segment "CODE"
.org $380C
map_control_0f380c:
    .byte $F1 ; progressive-copy count
    .byte $D9 ; same-value copy count/distance
