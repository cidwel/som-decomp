.setcpu "65816"
.segment "CODE"
.org $A0A7
map_control_0fa0a7:
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
