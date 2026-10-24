.setcpu "65816"
.segment "CODE"
.org $A69A
map_control_0fa69a:
    .byte $EB ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
