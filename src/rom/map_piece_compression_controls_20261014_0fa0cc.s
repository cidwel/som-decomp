.setcpu "65816"
.segment "CODE"
.org $A0CC
map_control_0fa0cc:
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
