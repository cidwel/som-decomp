.setcpu "65816"
.segment "CODE"
.org $BE4D
map_control_0ebe4d:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $21 ; distance low bit/count
