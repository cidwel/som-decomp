.setcpu "65816"
.segment "CODE"
.org $847F
map_control_0d847f:
    .byte $ED ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
