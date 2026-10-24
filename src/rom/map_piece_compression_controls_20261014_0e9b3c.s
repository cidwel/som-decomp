.setcpu "65816"
.segment "CODE"
.org $9B3C
map_control_0e9b3c:
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $AB ; row-distance/count
