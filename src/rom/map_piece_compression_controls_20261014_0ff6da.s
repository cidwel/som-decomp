.setcpu "65816"
.segment "CODE"
.org $F6DA
map_control_0ff6da:
    .byte $EF ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count
