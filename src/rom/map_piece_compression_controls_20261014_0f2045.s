.setcpu "65816"
.segment "CODE"
.org $2045
map_control_0f2045:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
