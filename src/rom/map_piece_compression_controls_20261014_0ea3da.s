.setcpu "65816"
.segment "CODE"
.org $A3DA
map_control_0ea3da:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
