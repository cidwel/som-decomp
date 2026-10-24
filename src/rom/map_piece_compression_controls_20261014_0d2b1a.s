.setcpu "65816"
.segment "CODE"
.org $2B1A
map_control_0d2b1a:
    .byte $ED ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
