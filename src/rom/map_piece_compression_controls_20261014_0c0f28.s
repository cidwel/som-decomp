.setcpu "65816"
.segment "CODE"
.org $0F28
map_control_0c0f28:
    .byte $EC ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
