.setcpu "65816"
.segment "CODE"
.org $EDBD
map_control_0eedbd:
    .byte $E0 ; previous-row copy escape
    .byte $94 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $93 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $92 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $93 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $FF ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $D4 ; row-distance/count
