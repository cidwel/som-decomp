.setcpu "65816"
.segment "CODE"
.org $3EE4
map_control_0c3ee4:
    .byte $EB ; backreference distance high bits
    .byte $03 ; distance low bit/count
