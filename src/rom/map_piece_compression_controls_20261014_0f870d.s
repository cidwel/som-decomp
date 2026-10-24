.setcpu "65816"
.segment "CODE"
.org $870D
map_control_0f870d:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
