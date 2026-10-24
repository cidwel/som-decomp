.setcpu "65816"
.segment "CODE"
.org $602B
map_control_0d602b:
    .byte $E0 ; previous-row copy escape
    .byte $95 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
