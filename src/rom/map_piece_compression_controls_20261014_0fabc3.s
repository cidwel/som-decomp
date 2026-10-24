.setcpu "65816"
.segment "CODE"
.org $ABC3
map_control_0fabc3:
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
