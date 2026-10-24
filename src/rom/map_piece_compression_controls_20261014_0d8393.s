.setcpu "65816"
.segment "CODE"
.org $8393
map_control_0d8393:
    .byte $F1 ; progressive-copy count
    .byte $DC ; same-value copy count/distance
