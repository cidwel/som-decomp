.setcpu "65816"
.segment "CODE"
.org $E390
map_control_0de390:
    .byte $ED ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E6 ; previous-row copy count
