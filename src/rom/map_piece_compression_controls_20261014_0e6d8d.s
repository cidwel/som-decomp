.setcpu "65816"
.segment "CODE"
.org $6D8D
map_control_0e6d8d:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $78 ; row-distance/count
