.setcpu "65816"
.segment "CODE"
.org $A6D7
map_control_0ea6d7:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
