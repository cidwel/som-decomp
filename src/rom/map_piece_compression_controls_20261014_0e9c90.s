.setcpu "65816"
.segment "CODE"
.org $9C90
map_control_0e9c90:
    .byte $E8 ; backreference distance high bits
    .byte $22 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
    .byte $EF ; backreference distance high bits
    .byte $8C ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $13 ; distance low bit/count
