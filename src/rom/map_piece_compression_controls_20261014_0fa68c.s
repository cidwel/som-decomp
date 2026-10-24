.setcpu "65816"
.segment "CODE"
.org $A68C
map_control_0fa68c:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
