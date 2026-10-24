.setcpu "65816"
.segment "CODE"
.org $3CBF
map_control_0c3cbf:
    .byte $EF ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
