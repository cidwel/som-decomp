.setcpu "65816"
.segment "CODE"
.org $F312
map_control_0ff312:
    .byte $EE ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
