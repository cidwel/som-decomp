.setcpu "65816"
.segment "CODE"
.org $EA26
map_control_0eea26:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
