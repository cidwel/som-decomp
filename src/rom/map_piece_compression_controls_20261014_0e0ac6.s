.setcpu "65816"
.segment "CODE"
.org $0AC6
map_control_0e0ac6:
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $1F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $5F ; row-distance/count
