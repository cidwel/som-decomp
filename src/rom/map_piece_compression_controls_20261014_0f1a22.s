.setcpu "65816"
.segment "CODE"
.org $1A22
map_control_0f1a22:
    .byte $ED ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E2 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
