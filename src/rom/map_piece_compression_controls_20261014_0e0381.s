.setcpu "65816"
.segment "CODE"
.org $0381
map_control_0e0381:
    .byte $E2 ; previous-row copy count
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
