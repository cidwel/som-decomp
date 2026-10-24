.setcpu "65816"
.segment "CODE"
.org $DC09
map_control_0ddc09:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
