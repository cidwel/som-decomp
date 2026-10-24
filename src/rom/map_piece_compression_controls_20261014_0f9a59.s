.setcpu "65816"
.segment "CODE"
.org $9A59
map_control_0f9a59:
    .byte $F1 ; progressive-copy count
    .byte $DC ; same-value copy count/distance
