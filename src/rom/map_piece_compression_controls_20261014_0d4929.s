.setcpu "65816"
.segment "CODE"
.org $4929
map_control_0d4929:
    .byte $EF ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
