.setcpu "65816"
.segment "CODE"
.org $EE0C
map_control_0eee0c:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $22 ; row-distance/count
