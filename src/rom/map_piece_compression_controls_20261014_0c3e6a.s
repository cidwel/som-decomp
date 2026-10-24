.setcpu "65816"
.segment "CODE"
.org $3E6A
map_control_0c3e6a:
    .byte $EA ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
