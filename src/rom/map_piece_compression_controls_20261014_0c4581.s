.setcpu "65816"
.segment "CODE"
.org $4581
map_control_0c4581:
    .byte $EB ; backreference distance high bits
    .byte $03 ; distance low bit/count
