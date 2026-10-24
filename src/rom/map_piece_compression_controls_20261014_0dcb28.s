.setcpu "65816"
.segment "CODE"
.org $CB28
map_control_0dcb28:
    .byte $F1 ; progressive-copy count
    .byte $DC ; same-value copy count/distance
