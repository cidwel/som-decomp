.setcpu "65816"
.segment "CODE"
.org $DA64
map_control_0fda64:
    .byte $E7 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
