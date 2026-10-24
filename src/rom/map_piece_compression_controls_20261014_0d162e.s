.setcpu "65816"
.segment "CODE"
.org $162E
map_control_0d162e:
    .byte $E8 ; backreference distance high bits
    .byte $9B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $A0 ; row-distance/count
