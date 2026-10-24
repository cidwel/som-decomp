.setcpu "65816"
.segment "CODE"
.org $2CF6
map_control_0c2cf6:
    .byte $EB ; backreference distance high bits
    .byte $03 ; distance low bit/count
