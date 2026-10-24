.setcpu "65816"
.segment "CODE"
.org $EBC2
map_control_0eebc2:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
