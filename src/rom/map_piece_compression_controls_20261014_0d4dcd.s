.setcpu "65816"
.segment "CODE"
.org $4DCD
map_control_0d4dcd:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
