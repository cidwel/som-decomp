.setcpu "65816"
.segment "CODE"
.org $A1DE
map_control_0ea1de:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $2A ; row-distance/count
