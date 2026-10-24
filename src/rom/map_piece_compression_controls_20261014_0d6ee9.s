.setcpu "65816"
.segment "CODE"
.org $6EE9
map_control_0d6ee9:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
    .byte $EF ; backreference distance high bits
    .byte $0C ; distance low bit/count
