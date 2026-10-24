.setcpu "65816"
.segment "CODE"
.org $228B
map_control_0e228b:
    .byte $EA ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
