.setcpu "65816"
.segment "CODE"
.org $F2F0
map_control_0df2f0:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
    .byte $EE ; backreference distance high bits
    .byte $07 ; distance low bit/count
