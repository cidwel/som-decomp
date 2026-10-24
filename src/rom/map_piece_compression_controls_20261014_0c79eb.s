.setcpu "65816"
.segment "CODE"
.org $79EB
map_control_0c79eb:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
