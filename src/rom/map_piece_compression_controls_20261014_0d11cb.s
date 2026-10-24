.setcpu "65816"
.segment "CODE"
.org $11CB
map_control_0d11cb:
    .byte $EB ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $05 ; distance low bit/count
