.setcpu "65816"
.segment "CODE"
.org $8DC3
map_control_0d8dc3:
    .byte $EF ; backreference distance high bits
    .byte $8C ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
