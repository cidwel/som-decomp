.setcpu "65816"
.segment "CODE"
.org $4135
map_control_0d4135:
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count
    .byte $E2 ; previous-row copy count
