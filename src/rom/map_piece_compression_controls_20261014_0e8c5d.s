.setcpu "65816"
.segment "CODE"
.org $8C5D
map_control_0e8c5d:
    .byte $F1 ; progressive-copy count
    .byte $DC ; same-value copy count/distance
