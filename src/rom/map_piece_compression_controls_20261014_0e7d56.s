.setcpu "65816"
.segment "CODE"
.org $7D56
map_control_0e7d56:
    .byte $F0 ; progressive-copy escape
    .byte $7F ; direction/count
    .byte $F0 ; progressive-copy escape
    .byte $3E ; direction/count
