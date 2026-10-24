.setcpu "65816"
.segment "CODE"
.org $4A90
map_control_0c4a90:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
