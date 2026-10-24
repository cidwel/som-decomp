.setcpu "65816"
.segment "CODE"
.org $AC68
map_control_0dac68:
    .byte $EF ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $36 ; distance low bit/count
