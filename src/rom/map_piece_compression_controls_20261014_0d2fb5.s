.setcpu "65816"
.segment "CODE"
.org $2FB5
map_control_0d2fb5:
    .byte $EC ; backreference distance high bits
    .byte $0D ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
