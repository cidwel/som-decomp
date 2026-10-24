.setcpu "65816"
.segment "CODE"
.org $2C95
map_control_0e2c95:
    .byte $EB ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
