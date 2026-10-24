.setcpu "65816"
.segment "CODE"
.org $CF2B
map_control_0fcf2b:
    .byte $E8 ; backreference distance high bits
    .byte $18 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
