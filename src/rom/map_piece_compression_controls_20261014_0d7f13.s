.setcpu "65816"
.segment "CODE"
.org $7F13
map_control_0d7f13:
    .byte $E1 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
