.setcpu "65816"
.segment "CODE"
.org $502D
map_control_0c502d:
    .byte $ED ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $0C ; distance low bit/count
    .byte $E6 ; previous-row copy count
