.setcpu "65816"
.segment "CODE"
.org $1B6B
map_control_0d1b6b:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
