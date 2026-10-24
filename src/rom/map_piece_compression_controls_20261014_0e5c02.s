.setcpu "65816"
.segment "CODE"
.org $5C02
map_control_0e5c02:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
