.setcpu "65816"
.segment "CODE"
.org $5A2F
map_control_0e5a2f:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $6B ; row-distance/count
