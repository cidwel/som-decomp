.setcpu "65816"
.segment "CODE"
.org $BC0C
map_control_0fbc0c:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
