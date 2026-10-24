.setcpu "65816"
.segment "CODE"
.org $4800
map_control_0d4800:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E5 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $89 ; distance low bit/count
