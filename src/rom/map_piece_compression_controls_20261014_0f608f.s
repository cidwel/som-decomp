.setcpu "65816"
.segment "CODE"
.org $608F
map_control_0f608f:
    .byte $E8 ; backreference distance high bits
    .byte $17 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
