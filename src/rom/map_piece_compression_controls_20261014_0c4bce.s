.setcpu "65816"
.segment "CODE"
.org $4BCE
map_control_0c4bce:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
