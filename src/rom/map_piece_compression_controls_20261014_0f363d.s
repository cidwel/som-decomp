.setcpu "65816"
.segment "CODE"
.org $363D
map_control_0f363d:
    .byte $F1 ; progressive-copy count
    .byte $DE ; same-value copy count/distance
