.setcpu "65816"
.segment "CODE"
.org $4D51
map_control_0d4d51:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
