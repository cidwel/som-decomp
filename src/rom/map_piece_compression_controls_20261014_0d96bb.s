.setcpu "65816"
.segment "CODE"
.org $96BB
map_control_0d96bb:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E2 ; previous-row copy count
