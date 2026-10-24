.setcpu "65816"
.segment "CODE"
.org $F6B5
map_control_0ef6b5:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
