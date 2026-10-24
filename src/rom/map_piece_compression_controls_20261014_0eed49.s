.setcpu "65816"
.segment "CODE"
.org $ED49
map_control_0eed49:
    .byte $E8 ; backreference distance high bits
    .byte $15 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $77 ; row-distance/count
