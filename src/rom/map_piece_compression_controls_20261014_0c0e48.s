.setcpu "65816"
.segment "CODE"
.org $0E48
map_control_0c0e48:
    .byte $EC ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $CF ; row-distance/count
