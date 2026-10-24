.setcpu "65816"
.segment "CODE"
.org $908C
map_control_0d908c:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $90 ; row-distance/count
