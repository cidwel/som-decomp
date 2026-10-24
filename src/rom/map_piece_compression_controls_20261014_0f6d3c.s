.setcpu "65816"
.segment "CODE"
.org $6D3C
map_control_0f6d3c:
    .byte $F1 ; progressive-copy count
    .byte $DC ; same-value copy count/distance
