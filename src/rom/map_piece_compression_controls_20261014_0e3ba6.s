.setcpu "65816"
.segment "CODE"
.org $3BA6
map_control_0e3ba6:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
