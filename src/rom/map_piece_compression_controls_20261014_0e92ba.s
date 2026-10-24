.setcpu "65816"
.segment "CODE"
.org $92BA
map_control_0e92ba:
    .byte $F1 ; progressive-copy count
    .byte $C2 ; same-value copy count/distance
