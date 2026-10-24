.setcpu "65816"
.segment "CODE"
.org $CC85
map_control_0ecc85:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
