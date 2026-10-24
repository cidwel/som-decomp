.setcpu "65816"
.segment "CODE"
.org $B242
map_control_0fb242:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
