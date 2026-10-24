.setcpu "65816"
.segment "CODE"
.org $F29A
map_control_0ef29a:
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
