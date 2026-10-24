.setcpu "65816"
.segment "CODE"
.org $8FBC
map_control_0e8fbc:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
