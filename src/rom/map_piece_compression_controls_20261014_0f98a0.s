.setcpu "65816"
.segment "CODE"
.org $98A0
map_control_0f98a0:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $46 ; row-distance/count
