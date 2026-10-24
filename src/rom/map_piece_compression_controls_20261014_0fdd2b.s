.setcpu "65816"
.segment "CODE"
.org $DD2B
map_control_0fdd2b:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $63 ; row-distance/count
