.setcpu "65816"
.segment "CODE"
.org $6186
map_control_0f6186:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
