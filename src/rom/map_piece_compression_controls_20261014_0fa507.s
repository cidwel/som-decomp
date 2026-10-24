.setcpu "65816"
.segment "CODE"
.org $A507
map_control_0fa507:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
