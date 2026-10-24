.setcpu "65816"
.segment "CODE"
.org $E883
map_control_0fe883:
    .byte $EF ; backreference distance high bits
    .byte $04 ; distance low bit/count
