.setcpu "65816"
.segment "CODE"
.org $EA1F
map_control_0dea1f:
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
