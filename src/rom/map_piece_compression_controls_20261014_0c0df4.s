.setcpu "65816"
.segment "CODE"
.org $0DF4
map_control_0c0df4:
    .byte $E9 ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $AB ; row-distance/count
