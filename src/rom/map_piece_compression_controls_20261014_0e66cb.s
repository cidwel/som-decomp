.setcpu "65816"
.segment "CODE"
.org $66CB
map_control_0e66cb:
    .byte $EA ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $26 ; row-distance/count
