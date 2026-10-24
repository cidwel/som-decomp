.setcpu "65816"
.segment "CODE"
.org $627F
map_control_0f627f:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $4F ; row-distance/count
