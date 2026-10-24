.setcpu "65816"
.segment "CODE"
.org $F11B
map_control_0ff11b:
    .byte $F1 ; progressive-copy count
