.setcpu "65816"
.segment "CODE"
.org $0A69
map_control_0f0a69:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $A1 ; row-distance/count
