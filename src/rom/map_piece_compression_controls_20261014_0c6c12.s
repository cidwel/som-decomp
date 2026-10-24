.setcpu "65816"
.segment "CODE"
.org $6C12
map_control_0c6c12:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
