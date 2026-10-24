.setcpu "65816"
.segment "CODE"
.org $5A5C
map_control_0e5a5c:
    .byte $F1 ; progressive-copy count
    .byte $DA ; same-value copy count/distance
