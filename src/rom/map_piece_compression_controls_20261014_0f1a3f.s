.setcpu "65816"
.segment "CODE"
.org $1A3F
map_control_0f1a3f:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $45 ; distance low bit/count
    .byte $E2 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $8C ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
