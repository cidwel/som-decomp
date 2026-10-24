.setcpu "65816"
.segment "CODE"
.org $B680
map_control_0fb680:
    .byte $E0 ; previous-row copy escape
    .byte $A5 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $38 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $64 ; row-distance/count
