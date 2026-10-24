.setcpu "65816"
.segment "CODE"
.org $0FAE
map_control_0c0fae:
    .byte $E7 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
