.setcpu "65816"
.segment "CODE"
.org $8EB8
map_control_0f8eb8:
    .byte $E9 ; backreference distance high bits
    .byte $17 ; distance low bit/count
