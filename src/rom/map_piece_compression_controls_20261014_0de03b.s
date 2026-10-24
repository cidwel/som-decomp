.setcpu "65816"
.segment "CODE"
.org $E03B
map_control_0de03b:
    .byte $E8 ; backreference distance high bits
    .byte $9B ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $0E ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $8E ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $E4 ; row-distance/count
