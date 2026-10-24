.setcpu "65816"
.segment "CODE"
.org $9440
map_control_0f9440:
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
