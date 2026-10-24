.setcpu "65816"
.segment "CODE"
.org $9A6E
map_control_0f9a6e:
    .byte $F1 ; progressive-copy count
    .byte $DC ; same-value copy count/distance
