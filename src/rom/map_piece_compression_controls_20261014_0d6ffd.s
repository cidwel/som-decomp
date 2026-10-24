.setcpu "65816"
.segment "CODE"
.org $6FFD
map_control_0d6ffd:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
