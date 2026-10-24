.setcpu "65816"
.segment "CODE"
.org $168B
map_control_0d168b:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
