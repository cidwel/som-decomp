.setcpu "65816"
.segment "CODE"
.org $FC4F
map_control_0dfc4f:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
