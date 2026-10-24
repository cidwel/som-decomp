.setcpu "65816"
.segment "CODE"
.org $FE76
map_control_0efe76:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
