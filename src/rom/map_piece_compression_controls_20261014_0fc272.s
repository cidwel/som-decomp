.setcpu "65816"
.segment "CODE"
.org $C272
map_control_0fc272:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $19 ; distance low bit/count
    .byte $E2 ; previous-row copy count
