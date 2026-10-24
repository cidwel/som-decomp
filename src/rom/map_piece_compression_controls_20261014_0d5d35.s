.setcpu "65816"
.segment "CODE"
.org $5D35
map_control_0d5d35:
    .byte $C1 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
