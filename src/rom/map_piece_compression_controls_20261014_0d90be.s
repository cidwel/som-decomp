.setcpu "65816"
.segment "CODE"
.org $90BE
map_control_0d90be:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
