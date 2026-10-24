.setcpu "65816"
.segment "CODE"
.org $561D
map_control_0c561d:
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
