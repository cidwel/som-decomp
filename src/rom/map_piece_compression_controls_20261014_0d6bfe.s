.setcpu "65816"
.segment "CODE"
.org $6BFE
map_control_0d6bfe:
    .byte $F1 ; progressive-copy count
    .byte $C4 ; same-value copy count/distance
