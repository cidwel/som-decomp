.setcpu "65816"
.segment "CODE"
.org $A17C
map_control_0ea17c:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $8F ; row-distance/count
