.setcpu "65816"
.segment "CODE"
.org $E3B4
map_control_0fe3b4:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $0D ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $4D ; distance low bit/count
