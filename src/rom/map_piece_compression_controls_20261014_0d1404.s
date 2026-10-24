.setcpu "65816"
.segment "CODE"
.org $1404
map_control_0d1404:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $95 ; row-distance/count
