.setcpu "65816"
.segment "CODE"
.org $9351
map_control_0d9351:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
