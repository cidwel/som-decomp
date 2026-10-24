.setcpu "65816"
.segment "CODE"
.org $89F7
map_control_0d89f7:
    .byte $E0 ; previous-row copy escape
    .byte $A0 ; row-distance/count
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
