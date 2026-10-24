.setcpu "65816"
.segment "CODE"
.org $F100
map_control_0df100:
    .byte $F2 ; progressive-copy count
