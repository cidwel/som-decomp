.setcpu "65816"
.segment "CODE"
.org $4014
map_control_0d4014:
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
