.setcpu "65816"
.segment "CODE"
.org $ED3A
map_control_0eed3a:
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
