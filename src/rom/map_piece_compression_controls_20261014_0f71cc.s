.setcpu "65816"
.segment "CODE"
.org $71CC
map_control_0f71cc:
    .byte $F1 ; progressive-copy count
