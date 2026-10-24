.setcpu "65816"
.segment "CODE"
.org $86EF
map_control_0d86ef:
    .byte $EF ; backreference distance high bits
    .byte $9E ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
