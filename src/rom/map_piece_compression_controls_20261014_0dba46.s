.setcpu "65816"
.segment "CODE"
.org $BA46
map_control_0dba46:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $06 ; distance low bit/count
