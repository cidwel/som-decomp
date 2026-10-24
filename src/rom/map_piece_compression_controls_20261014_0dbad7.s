.setcpu "65816"
.segment "CODE"
.org $BAD7
map_control_0dbad7:
    .byte $E8 ; backreference distance high bits
    .byte $8E ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
