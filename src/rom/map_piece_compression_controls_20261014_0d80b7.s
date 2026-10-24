.setcpu "65816"
.segment "CODE"
.org $80B7
map_control_0d80b7:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $34 ; row-distance/count
