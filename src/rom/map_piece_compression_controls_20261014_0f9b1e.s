.setcpu "65816"
.segment "CODE"
.org $9B1E
map_control_0f9b1e:
    .byte $F1 ; progressive-copy count
    .byte $DA ; same-value copy count/distance
