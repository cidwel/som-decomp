.setcpu "65816"
.segment "CODE"
.org $E67D
map_control_0fe67d:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
