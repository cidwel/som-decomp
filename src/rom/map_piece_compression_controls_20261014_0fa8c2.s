.setcpu "65816"
.segment "CODE"
.org $A8C2
map_control_0fa8c2:
    .byte $EB ; backreference distance high bits
    .byte $8E ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
