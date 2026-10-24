.setcpu "65816"
.segment "CODE"
.org $A818
map_control_0fa818:
    .byte $EC ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
