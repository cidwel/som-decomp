.setcpu "65816"
.segment "CODE"
.org $8E8D
map_control_0c8e8d:
    .byte $F0 ; progressive-copy escape
    .byte $08 ; direction/count
