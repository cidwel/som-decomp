.setcpu "65816"
.segment "CODE"
.org $302F
map_control_0e302f:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
