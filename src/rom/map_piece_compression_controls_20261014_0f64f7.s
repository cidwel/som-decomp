.setcpu "65816"
.segment "CODE"
.org $64F7
map_control_0f64f7:
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $48 ; distance low bit/count
