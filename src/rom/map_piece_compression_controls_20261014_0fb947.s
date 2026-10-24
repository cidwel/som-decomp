.setcpu "65816"
.segment "CODE"
.org $B947
map_control_0fb947:
    .byte $E0 ; previous-row copy escape
    .byte $B3 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $ED ; backreference distance high bits
    .byte $89 ; distance low bit/count
