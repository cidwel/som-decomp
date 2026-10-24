.setcpu "65816"
.segment "CODE"
.org $D4E3
map_control_0fd4e3:
    .byte $E8 ; backreference distance high bits
    .byte $13 ; distance low bit/count
    .byte $E7 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
