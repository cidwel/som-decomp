.setcpu "65816"
.segment "CODE"
.org $E3AD
map_control_0fe3ad:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $11 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $8A ; row-distance/count
