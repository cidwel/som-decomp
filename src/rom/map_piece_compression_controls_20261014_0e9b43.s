.setcpu "65816"
.segment "CODE"
.org $9B43
map_control_0e9b43:
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count
    .byte $EA ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $AB ; row-distance/count
