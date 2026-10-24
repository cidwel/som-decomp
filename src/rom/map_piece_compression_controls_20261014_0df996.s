.setcpu "65816"
.segment "CODE"
.org $F996
map_control_0df996:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
