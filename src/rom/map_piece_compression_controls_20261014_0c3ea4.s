.setcpu "65816"
.segment "CODE"
.org $3EA4
map_control_0c3ea4:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
