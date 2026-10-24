.setcpu "65816"
.segment "CODE"
.org $BCB8
map_control_0ebcb8:
    .byte $F1 ; progressive-copy count
    .byte $DD ; same-value copy count/distance
