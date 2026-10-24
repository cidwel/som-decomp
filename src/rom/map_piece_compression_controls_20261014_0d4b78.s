.setcpu "65816"
.segment "CODE"
.org $4B78
map_control_0d4b78:
    .byte $F0 ; progressive-copy escape
    .byte $82 ; direction/count
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
