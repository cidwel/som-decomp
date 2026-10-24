.setcpu "65816"
.segment "CODE"
.org $F541
map_control_0df541:
    .byte $EF ; backreference distance high bits
    .byte $8E ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
