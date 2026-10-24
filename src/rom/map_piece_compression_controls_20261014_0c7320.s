.setcpu "65816"
.segment "CODE"
.org $7320
map_control_0c7320:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
