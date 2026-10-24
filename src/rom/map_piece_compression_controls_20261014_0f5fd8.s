.setcpu "65816"
.segment "CODE"
.org $5FD8
map_control_0f5fd8:
    .byte $EF ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $E5 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $04 ; distance low bit/count
