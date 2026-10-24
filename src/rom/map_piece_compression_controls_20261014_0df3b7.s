.setcpu "65816"
.segment "CODE"
.org $F3B7
map_control_0df3b7:
    .byte $F1 ; progressive-copy count
    .byte $DC ; same-value copy count/distance
