.setcpu "65816"
.segment "CODE"
.org $FF06
map_control_0eff06:
    .byte $E6 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
