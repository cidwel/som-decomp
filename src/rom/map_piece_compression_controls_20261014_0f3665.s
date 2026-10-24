.setcpu "65816"
.segment "CODE"
.org $3665
map_control_0f3665:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
