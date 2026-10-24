.setcpu "65816"
.segment "CODE"
.org $D632
map_control_0ed632:
    .byte $EC ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
