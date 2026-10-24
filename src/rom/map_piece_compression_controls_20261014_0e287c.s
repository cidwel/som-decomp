.setcpu "65816"
.segment "CODE"
.org $287C
map_control_0e287c:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $33 ; row-distance/count
