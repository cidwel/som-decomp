.setcpu "65816"
.segment "CODE"
.org $345F
map_control_0d345f:
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
