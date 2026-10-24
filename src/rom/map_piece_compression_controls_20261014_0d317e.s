.setcpu "65816"
.segment "CODE"
.org $317E
map_control_0d317e:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $6E ; row-distance/count
