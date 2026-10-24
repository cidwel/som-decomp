.setcpu "65816"
.segment "CODE"
.org $F666
map_control_0ff666:
    .byte $EF ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
