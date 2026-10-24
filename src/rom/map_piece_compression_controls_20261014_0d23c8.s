.setcpu "65816"
.segment "CODE"
.org $23C8
map_control_0d23c8:
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $AB ; row-distance/count
