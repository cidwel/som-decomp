.setcpu "65816"
.segment "CODE"
.org $5B52
map_control_0d5b52:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
