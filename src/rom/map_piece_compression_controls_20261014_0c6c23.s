.setcpu "65816"
.segment "CODE"
.org $6C23
map_control_0c6c23:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
