.setcpu "65816"
.segment "CODE"
.org $4D63
map_control_0f4d63:
    .byte $EF ; backreference distance high bits
    .byte $8E ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
