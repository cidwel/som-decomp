.setcpu "65816"
.segment "CODE"
.org $18CE
map_control_0d18ce:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $90 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
