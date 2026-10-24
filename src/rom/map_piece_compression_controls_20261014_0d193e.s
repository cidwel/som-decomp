.setcpu "65816"
.segment "CODE"
.org $193E
map_control_0d193e:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E1 ; previous-row copy count
