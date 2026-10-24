.setcpu "65816"
.segment "CODE"
.org $A0E8
map_control_0ea0e8:
    .byte $ED ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
