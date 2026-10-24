.setcpu "65816"
.segment "CODE"
.org $21D0
map_control_0d21d0:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $8C ; row-distance/count
