.setcpu "65816"
.segment "CODE"
.org $ABDA
map_control_0dabda:
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
