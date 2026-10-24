.setcpu "65816"
.segment "CODE"
.org $2066
map_control_0f2066:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
