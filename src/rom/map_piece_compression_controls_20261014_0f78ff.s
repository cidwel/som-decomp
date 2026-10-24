.setcpu "65816"
.segment "CODE"
.org $78FF
map_control_0f78ff:
    .byte $F1 ; progressive-copy count
