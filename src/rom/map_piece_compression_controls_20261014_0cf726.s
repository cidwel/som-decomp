.setcpu "65816"
.segment "CODE"
.org $F726
map_control_0cf726:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
