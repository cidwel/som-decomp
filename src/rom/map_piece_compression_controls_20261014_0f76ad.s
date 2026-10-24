.setcpu "65816"
.segment "CODE"
.org $76AD
map_control_0f76ad:
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $8C ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
