.setcpu "65816"
.segment "CODE"
.org $63A4
map_control_0e63a4:
    .byte $ED ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
