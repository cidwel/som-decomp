.setcpu "65816"
.segment "CODE"
.org $EC07
map_control_0eec07:
    .byte $E8 ; backreference distance high bits
    .byte $14 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
