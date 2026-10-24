.setcpu "65816"
.segment "CODE"
.org $2B63
map_control_0d2b63:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
