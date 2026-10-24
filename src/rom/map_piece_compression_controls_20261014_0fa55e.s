.setcpu "65816"
.segment "CODE"
.org $A55E
map_control_0fa55e:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $45 ; row-distance/count
