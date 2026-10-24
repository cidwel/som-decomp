.setcpu "65816"
.segment "CODE"
.org $E600
map_control_0fe600:
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
