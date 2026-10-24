.setcpu "65816"
.segment "CODE"
.org $8B96
map_control_0e8b96:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
