.setcpu "65816"
.segment "CODE"
.org $7489
map_control_0d7489:
    .byte $F1 ; progressive-copy count
    .byte $DA ; same-value copy count/distance
