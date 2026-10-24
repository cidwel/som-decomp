.setcpu "65816"
.segment "CODE"
.org $75D0
map_control_0e75d0:
    .byte $F1 ; progressive-copy count
    .byte $DD ; same-value copy count/distance
