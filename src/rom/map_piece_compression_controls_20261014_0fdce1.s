.setcpu "65816"
.segment "CODE"
.org $DCE1
map_control_0fdce1:
    .byte $EC ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $57 ; row-distance/count
