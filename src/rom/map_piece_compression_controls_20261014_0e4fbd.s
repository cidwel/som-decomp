.setcpu "65816"
.segment "CODE"
.org $4FBD
map_control_0e4fbd:
    .byte $F1 ; progressive-copy count
    .byte $C1 ; same-value copy count/distance
