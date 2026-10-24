.setcpu "65816"
.segment "CODE"
.org $07F6
map_control_0e07f6:
    .byte $DC ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
