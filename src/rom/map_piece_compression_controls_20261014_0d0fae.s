.setcpu "65816"
.segment "CODE"
.org $0FAE
map_control_0d0fae:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E2 ; previous-row copy count
