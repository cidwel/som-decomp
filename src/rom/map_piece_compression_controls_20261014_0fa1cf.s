.setcpu "65816"
.segment "CODE"
.org $A1CF
map_control_0fa1cf:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $E1 ; previous-row copy count
