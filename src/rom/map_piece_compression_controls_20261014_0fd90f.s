.setcpu "65816"
.segment "CODE"
.org $D90F
map_control_0fd90f:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $64 ; row-distance/count
