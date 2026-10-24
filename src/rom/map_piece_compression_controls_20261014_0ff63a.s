.setcpu "65816"
.segment "CODE"
.org $F63A
map_control_0ff63a:
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count
