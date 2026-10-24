.setcpu "65816"
.segment "CODE"
.org $9DBC
map_control_0d9dbc:
    .byte $EF ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $B4 ; row-distance/count
