.setcpu "65816"
.segment "CODE"
.org $49DB
map_control_0d49db:
    .byte $E0 ; previous-row copy escape
    .byte $87 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
