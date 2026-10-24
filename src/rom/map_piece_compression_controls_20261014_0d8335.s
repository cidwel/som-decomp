.setcpu "65816"
.segment "CODE"
.org $8335
map_control_0d8335:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
