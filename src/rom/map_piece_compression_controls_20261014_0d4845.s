.setcpu "65816"
.segment "CODE"
.org $4845
map_control_0d4845:
    .byte $EF ; backreference distance high bits
    .byte $07 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E5 ; previous-row copy count
