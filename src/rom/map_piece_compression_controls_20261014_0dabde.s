.setcpu "65816"
.segment "CODE"
.org $ABDE
map_control_0dabde:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
