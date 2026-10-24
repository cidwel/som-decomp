.setcpu "65816"
.segment "CODE"
.org $A12E
map_control_0ea12e:
    .byte $EC ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
