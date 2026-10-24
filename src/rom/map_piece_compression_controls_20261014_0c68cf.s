.setcpu "65816"
.segment "CODE"
.org $68CF
map_control_0c68cf:
    .byte $EB ; backreference distance high bits
    .byte $03 ; distance low bit/count
