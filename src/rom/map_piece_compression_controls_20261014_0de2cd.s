.setcpu "65816"
.segment "CODE"
.org $E2CD
map_control_0de2cd:
    .byte $E8 ; backreference distance high bits
    .byte $16 ; distance low bit/count
    .byte $E1 ; previous-row copy count
