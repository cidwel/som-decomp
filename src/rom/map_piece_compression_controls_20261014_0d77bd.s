.setcpu "65816"
.segment "CODE"
.org $77BD
map_control_0d77bd:
    .byte $F1 ; progressive-copy count
    .byte $D9 ; same-value copy count/distance
