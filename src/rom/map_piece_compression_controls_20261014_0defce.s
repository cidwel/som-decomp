.setcpu "65816"
.segment "CODE"
.org $EFCE
map_control_0defce:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $54 ; row-distance/count
