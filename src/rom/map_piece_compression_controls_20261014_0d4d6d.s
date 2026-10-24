.setcpu "65816"
.segment "CODE"
.org $4D6D
map_control_0d4d6d:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
