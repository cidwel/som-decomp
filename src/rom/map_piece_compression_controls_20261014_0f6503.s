.setcpu "65816"
.segment "CODE"
.org $6503
map_control_0f6503:
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $64 ; distance low bit/count
