.setcpu "65816"
.segment "CODE"
.org $BE9B
map_control_0ebe9b:
    .byte $E8 ; backreference distance high bits
    .byte $15 ; distance low bit/count
    .byte $E5 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
