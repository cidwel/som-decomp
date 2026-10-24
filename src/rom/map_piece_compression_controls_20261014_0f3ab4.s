.setcpu "65816"
.segment "CODE"
.org $3AB4
map_control_0f3ab4:
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
