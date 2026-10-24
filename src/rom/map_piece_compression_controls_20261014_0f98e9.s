.setcpu "65816"
.segment "CODE"
.org $98E9
map_control_0f98e9:
    .byte $E0 ; previous-row copy escape
    .byte $89 ; row-distance/count
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
