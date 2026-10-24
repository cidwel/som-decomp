.setcpu "65816"
.segment "CODE"
.org $05D8
map_control_0e05d8:
    .byte $F1 ; progressive-copy count
    .byte $DC ; same-value copy count/distance
