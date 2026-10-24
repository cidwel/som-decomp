.setcpu "65816"
.segment "CODE"
.org $7862
map_control_0d7862:
    .byte $E0 ; previous-row copy escape
    .byte $4D ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $77 ; row-distance/count
