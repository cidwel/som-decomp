.setcpu "65816"
.segment "CODE"
.org $FDC1
map_control_0dfdc1:
    .byte $F1 ; progressive-copy count
    .byte $DC ; same-value copy count/distance
