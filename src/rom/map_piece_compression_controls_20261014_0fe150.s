.setcpu "65816"
.segment "CODE"
.org $E150
map_control_0fe150:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $66 ; row-distance/count
