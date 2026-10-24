.setcpu "65816"
.segment "CODE"
.org $5C4F
map_control_0d5c4f:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
