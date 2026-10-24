.setcpu "65816"
.segment "CODE"
.org $9B4F
map_control_0e9b4f:
    .byte $EB ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $AB ; row-distance/count
