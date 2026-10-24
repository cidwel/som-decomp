.setcpu "65816"
.segment "CODE"
.org $0671
map_control_0f0671:
    .byte $D1 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
