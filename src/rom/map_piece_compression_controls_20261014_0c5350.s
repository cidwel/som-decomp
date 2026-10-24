.setcpu "65816"
.segment "CODE"
.org $5350
map_control_0c5350:
    .byte $EF ; backreference distance high bits
    .byte $9A ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
