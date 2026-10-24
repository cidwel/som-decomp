.setcpu "65816"
.segment "CODE"
.org $0E40
map_control_0c0e40:
    .byte $EC ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $C1 ; row-distance/count
