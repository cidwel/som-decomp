.setcpu "65816"
.segment "CODE"
.org $A7F9
map_control_0fa7f9:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $76 ; row-distance/count
