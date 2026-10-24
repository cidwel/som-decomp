.setcpu "65816"
.segment "CODE"
.org $5A9E
map_control_0e5a9e:
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $8C ; row-distance/count
