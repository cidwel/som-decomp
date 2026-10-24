.setcpu "65816"
.segment "CODE"
.org $93DF
map_control_0e93df:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
