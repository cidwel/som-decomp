.setcpu "65816"
.segment "CODE"
.org $23C0
map_control_0d23c0:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
    .byte $EF ; backreference distance high bits
    .byte $8C ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $2C ; row-distance/count
