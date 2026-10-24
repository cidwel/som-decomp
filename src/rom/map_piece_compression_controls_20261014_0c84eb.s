.setcpu "65816"
.segment "CODE"
.org $84EB
map_control_0c84eb:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
