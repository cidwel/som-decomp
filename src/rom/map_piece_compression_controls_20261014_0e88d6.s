.setcpu "65816"
.segment "CODE"
.org $88D6
map_control_0e88d6:
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
