.setcpu "65816"
.segment "CODE"
.org $9394
map_control_0e9394:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
