.setcpu "65816"
.segment "CODE"
.org $C9D1
map_control_0ec9d1:
    .byte $E8 ; backreference distance high bits
    .byte $A2 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
