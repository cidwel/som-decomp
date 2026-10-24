.setcpu "65816"
.segment "CODE"
.org $8550
map_control_0f8550:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
