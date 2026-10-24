.setcpu "65816"
.segment "CODE"
.org $BB4C
map_control_0fbb4c:
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
