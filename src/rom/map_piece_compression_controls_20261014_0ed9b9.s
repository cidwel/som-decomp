.setcpu "65816"
.segment "CODE"
.org $D9B9
map_control_0ed9b9:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $64 ; row-distance/count
