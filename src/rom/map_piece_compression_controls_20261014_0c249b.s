.setcpu "65816"
.segment "CODE"
.org $249B
map_control_0c249b:
    .byte $EF ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
