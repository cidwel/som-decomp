.setcpu "65816"
.segment "CODE"
.org $3BF7
map_control_0f3bf7:
    .byte $E0 ; previous-row copy escape
    .byte $28 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $37 ; distance low bit/count
