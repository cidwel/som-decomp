.setcpu "65816"
.segment "CODE"
.org $800B
map_control_0f800b:
    .byte $F1 ; progressive-copy count
