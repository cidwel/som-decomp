.setcpu "65816"
.segment "CODE"
.org $19E3
map_control_0d19e3:
    .byte $F1 ; progressive-copy count
    .byte $DC ; same-value copy count/distance
