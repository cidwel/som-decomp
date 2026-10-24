.setcpu "65816"
.segment "CODE"
.org $9CC9
map_control_0d9cc9:
    .byte $F0 ; progressive-copy escape
    .byte $82 ; direction/count
