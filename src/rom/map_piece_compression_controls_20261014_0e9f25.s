.setcpu "65816"
.segment "CODE"
.org $9F25
map_control_0e9f25:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $8E ; row-distance/count
