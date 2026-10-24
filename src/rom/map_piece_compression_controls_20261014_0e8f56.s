.setcpu "65816"
.segment "CODE"
.org $8F56
map_control_0e8f56:
    .byte $EA ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
