.setcpu "65816"
.segment "CODE"
.org $EE38
map_control_0eee38:
    .byte $F1 ; progressive-copy count
    .byte $DC ; same-value copy count/distance
