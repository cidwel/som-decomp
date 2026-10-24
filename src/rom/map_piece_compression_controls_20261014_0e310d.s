.setcpu "65816"
.segment "CODE"
.org $310D
map_control_0e310d:
    .byte $EB ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
