.setcpu "65816"
.segment "CODE"
.org $1DDE
map_control_0d1dde:
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
