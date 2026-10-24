.setcpu "65816"
.segment "CODE"
.org $8B2E
map_control_0f8b2e:
    .byte $E8 ; backreference distance high bits
    .byte $24 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $34 ; distance low bit/count
