.setcpu "65816"
.segment "CODE"
.org $5C65
map_control_0f5c65:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
    .byte $EC ; backreference distance high bits
    .byte $08 ; distance low bit/count
