.setcpu "65816"
.segment "CODE"
.org $75C9
map_control_0f75c9:
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
