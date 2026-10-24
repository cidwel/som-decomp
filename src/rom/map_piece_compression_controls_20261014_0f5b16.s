.setcpu "65816"
.segment "CODE"
.org $5B16
map_control_0f5b16:
    .byte $F1 ; progressive-copy count
    .byte $DF ; same-value copy count/distance
