.setcpu "65816"
.segment "CODE"
.org $2FFF
map_control_0f2fff:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
    .byte $ED ; backreference distance high bits
    .byte $88 ; distance low bit/count
