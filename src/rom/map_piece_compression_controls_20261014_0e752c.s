.setcpu "65816"
.segment "CODE"
.org $752C
map_control_0e752c:
    .byte $F1 ; progressive-copy count
    .byte $DA ; same-value copy count/distance
