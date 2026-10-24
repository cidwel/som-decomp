.setcpu "65816"
.segment "CODE"
.org $EBFB
map_control_0eebfb:
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $4F ; row-distance/count
