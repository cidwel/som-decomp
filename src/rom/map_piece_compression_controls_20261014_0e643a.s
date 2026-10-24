.setcpu "65816"
.segment "CODE"
.org $643A
map_control_0e643a:
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
