.setcpu "65816"
.segment "CODE"
.org $F1E3
map_control_0df1e3:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $37 ; row-distance/count
