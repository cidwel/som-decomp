.setcpu "65816"
.segment "CODE"
.org $423B
map_control_0d423b:
    .byte $F0 ; progressive-copy escape
    .byte $82 ; direction/count
