.setcpu "65816"
.segment "CODE"
.org $35E6
map_control_0e35e6:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E6 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $0A ; distance low bit/count
