.setcpu "65816"
.segment "CODE"
.org $9CE2
map_control_0d9ce2:
    .byte $F0 ; progressive-copy escape
    .byte $82 ; direction/count
