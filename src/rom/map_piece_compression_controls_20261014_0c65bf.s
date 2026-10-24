.setcpu "65816"
.segment "CODE"
.org $65BF
map_control_0c65bf:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $62 ; row-distance/count
