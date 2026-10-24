.setcpu "65816"
.segment "CODE"
.org $964A
map_control_0e964a:
    .byte $ED ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
