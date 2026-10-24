.setcpu "65816"
.segment "CODE"
.org $4421
map_control_0f4421:
    .byte $EF ; backreference distance high bits
    .byte $8C ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $53 ; row-distance/count
