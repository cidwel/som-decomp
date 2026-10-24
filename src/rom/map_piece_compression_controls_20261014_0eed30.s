.setcpu "65816"
.segment "CODE"
.org $ED30
map_control_0eed30:
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
