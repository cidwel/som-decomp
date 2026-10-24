.setcpu "65816"
.segment "CODE"
.org $DD36
map_control_0ddd36:
    .byte $ED ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
