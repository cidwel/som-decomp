.setcpu "65816"
.segment "CODE"
.org $2B8A
map_control_0d2b8a:
    .byte $E0 ; previous-row copy escape
    .byte $2C ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
