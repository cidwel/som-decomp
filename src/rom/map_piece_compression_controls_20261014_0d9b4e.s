.setcpu "65816"
.segment "CODE"
.org $9B4E
map_control_0d9b4e:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E1 ; previous-row copy count
