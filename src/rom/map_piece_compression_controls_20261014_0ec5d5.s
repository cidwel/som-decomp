.setcpu "65816"
.segment "CODE"
.org $C5D5
map_control_0ec5d5:
    .byte $F1 ; progressive-copy count
    .byte $C2 ; same-value copy count/distance
