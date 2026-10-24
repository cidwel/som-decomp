.setcpu "65816"
.segment "CODE"
.org $9D6B
map_control_0d9d6b:
    .byte $EF ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $B1 ; row-distance/count
