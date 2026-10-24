.setcpu "65816"
.segment "CODE"
.org $0243
map_control_0f0243:
    .byte $E1 ; previous-row copy count
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
