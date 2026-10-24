.setcpu "65816"
.segment "CODE"
.org $7151
map_control_0c7151:
    .byte $EF ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
