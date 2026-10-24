.setcpu "65816"
.segment "CODE"
.org $E6D0
map_control_0fe6d0:
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $8A ; row-distance/count
