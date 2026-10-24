.setcpu "65816"
.segment "CODE"
.org $BAC9
map_control_0dbac9:
    .byte $E8 ; backreference distance high bits
    .byte $8E ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
