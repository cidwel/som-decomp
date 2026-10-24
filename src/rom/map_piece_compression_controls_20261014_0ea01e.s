.setcpu "65816"
.segment "CODE"
.org $A01E
map_control_0ea01e:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
