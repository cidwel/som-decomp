.setcpu "65816"
.segment "CODE"
.org $A161
map_control_0ea161:
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
