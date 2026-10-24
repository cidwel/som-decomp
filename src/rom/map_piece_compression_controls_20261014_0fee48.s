.setcpu "65816"
.segment "CODE"
.org $EE48
map_control_0fee48:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
