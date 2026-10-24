.setcpu "65816"
.segment "CODE"
.org $A96A
map_control_0ea96a:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $2B ; row-distance/count
