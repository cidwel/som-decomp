.setcpu "65816"
.segment "CODE"
.org $4DA0
map_control_0d4da0:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
