.setcpu "65816"
.segment "CODE"
.org $7313
map_control_0f7313:
    .byte $F1 ; progressive-copy count
    .byte $CA ; same-value copy count/distance
