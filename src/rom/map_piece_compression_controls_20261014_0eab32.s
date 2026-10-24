.setcpu "65816"
.segment "CODE"
.org $AB32
map_control_0eab32:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
