.setcpu "65816"
.segment "CODE"
.org $AEC9
map_control_0daec9:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
