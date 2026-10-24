.setcpu "65816"
.segment "CODE"
.org $6085
map_control_0d6085:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
