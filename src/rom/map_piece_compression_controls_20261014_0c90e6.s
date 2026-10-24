.setcpu "65816"
.segment "CODE"
.org $90E6
map_control_0c90e6:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
