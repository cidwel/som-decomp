.setcpu "65816"
.segment "CODE"
.org $66EF
map_control_0f66ef:
    .byte $EA ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $AB ; row-distance/count
