.setcpu "65816"
.segment "CODE"
.org $A109
map_control_0ea109:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
