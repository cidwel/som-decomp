.setcpu "65816"
.segment "CODE"
.org $5EA9
map_control_0c5ea9:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
