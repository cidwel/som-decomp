.setcpu "65816"
.segment "CODE"
.org $6C01
map_control_0c6c01:
    .byte $F1 ; progressive-copy count
    .byte $DA ; same-value copy count/distance
