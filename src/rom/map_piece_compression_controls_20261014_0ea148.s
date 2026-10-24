.setcpu "65816"
.segment "CODE"
.org $A148
map_control_0ea148:
    .byte $EC ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
