.setcpu "65816"
.segment "CODE"
.org $0D38
map_control_0d0d38:
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $87 ; row-distance/count
