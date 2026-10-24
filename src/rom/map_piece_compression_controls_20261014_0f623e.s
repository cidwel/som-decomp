.setcpu "65816"
.segment "CODE"
.org $623E
map_control_0f623e:
    .byte $EF ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $0E ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
