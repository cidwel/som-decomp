.setcpu "65816"
.segment "CODE"
.org $71E0
map_control_0f71e0:
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
