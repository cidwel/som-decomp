.setcpu "65816"
.segment "CODE"
.org $836B
map_control_0c836b:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
