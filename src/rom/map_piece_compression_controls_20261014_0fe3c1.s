.setcpu "65816"
.segment "CODE"
.org $E3C1
map_control_0fe3c1:
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $48 ; row-distance/count
