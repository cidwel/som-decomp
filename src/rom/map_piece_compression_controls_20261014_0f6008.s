.setcpu "65816"
.segment "CODE"
.org $6008
map_control_0f6008:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
    .byte $ED ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $54 ; row-distance/count
