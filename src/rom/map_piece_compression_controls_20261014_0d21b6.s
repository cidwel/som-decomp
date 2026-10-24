.setcpu "65816"
.segment "CODE"
.org $21B6
map_control_0d21b6:
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
