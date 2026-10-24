.setcpu "65816"
.segment "CODE"
.org $A8B5
map_control_0fa8b5:
    .byte $E0 ; previous-row copy escape
    .byte $2D ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $2F ; distance low bit/count
