.setcpu "65816"
.segment "CODE"
.org $420F
map_control_0d420f:
    .byte $F0 ; progressive-copy escape
    .byte $82 ; direction/count
