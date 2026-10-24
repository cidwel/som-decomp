.setcpu "65816"
.segment "CODE"
.org $1015
map_control_0e1015:
    .byte $F1 ; progressive-copy count
    .byte $DC ; same-value copy count/distance
