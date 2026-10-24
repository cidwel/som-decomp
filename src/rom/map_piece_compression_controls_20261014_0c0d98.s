.setcpu "65816"
.segment "CODE"
.org $0D98
map_control_0c0d98:
    .byte $EC ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $87 ; row-distance/count
