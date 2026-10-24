.setcpu "65816"
.segment "CODE"
.org $5771
map_control_0e5771:
    .byte $EF ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
