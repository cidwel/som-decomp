.setcpu "65816"
.segment "CODE"
.org $8374
map_control_0e8374:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
