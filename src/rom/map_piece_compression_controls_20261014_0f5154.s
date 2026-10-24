.setcpu "65816"
.segment "CODE"
.org $5154
map_control_0f5154:
    .byte $ED ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
