.setcpu "65816"
.segment "CODE"
.org $2EED
map_control_0d2eed:
    .byte $E0 ; previous-row copy escape
    .byte $91 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $2C ; row-distance/count
