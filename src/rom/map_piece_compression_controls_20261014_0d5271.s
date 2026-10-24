.setcpu "65816"
.segment "CODE"
.org $5271
map_control_0d5271:
    .byte $F1 ; progressive-copy count
    .byte $DC ; same-value copy count/distance
