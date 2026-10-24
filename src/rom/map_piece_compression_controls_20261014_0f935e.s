.setcpu "65816"
.segment "CODE"
.org $935E
map_control_0f935e:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
