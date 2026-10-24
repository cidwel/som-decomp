.setcpu "65816"
.segment "CODE"
.org $7B15
map_control_0d7b15:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count
