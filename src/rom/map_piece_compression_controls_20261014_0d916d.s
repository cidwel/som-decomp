.setcpu "65816"
.segment "CODE"
.org $916D
map_control_0d916d:
    .byte $E8 ; backreference distance high bits
    .byte $1E ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count
