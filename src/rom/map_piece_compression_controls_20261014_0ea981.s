.setcpu "65816"
.segment "CODE"
.org $A981
map_control_0ea981:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
