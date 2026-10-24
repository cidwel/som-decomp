.setcpu "65816"
.segment "CODE"
.org $572A
map_control_0c572a:
    .byte $ED ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $8E ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
