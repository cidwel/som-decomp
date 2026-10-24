.setcpu "65816"
.segment "CODE"
.org $84EA
map_control_0d84ea:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $EC ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
