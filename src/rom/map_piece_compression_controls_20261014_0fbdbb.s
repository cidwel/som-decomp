.setcpu "65816"
.segment "CODE"
.org $BDBB
map_control_0fbdbb:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $1A ; distance low bit/count
