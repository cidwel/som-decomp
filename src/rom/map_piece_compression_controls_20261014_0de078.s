.setcpu "65816"
.segment "CODE"
.org $E078
map_control_0de078:
    .byte $EC ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
