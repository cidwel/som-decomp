.setcpu "65816"
.segment "CODE"
.org $B7CF
map_control_0eb7cf:
    .byte $ED ; backreference distance high bits
    .byte $14 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
