.setcpu "65816"
.segment "CODE"
.org $11C5
map_control_0d11c5:
    .byte $F1 ; progressive-copy count
    .byte $DC ; same-value copy count/distance
