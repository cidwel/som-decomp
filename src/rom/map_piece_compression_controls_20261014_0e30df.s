.setcpu "65816"
.segment "CODE"
.org $30DF
map_control_0e30df:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count
