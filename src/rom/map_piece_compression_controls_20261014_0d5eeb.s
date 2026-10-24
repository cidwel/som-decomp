.setcpu "65816"
.segment "CODE"
.org $5EEB
map_control_0d5eeb:
    .byte $E8 ; backreference distance high bits
    .byte $19 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
