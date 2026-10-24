.setcpu "65816"
.segment "CODE"
.org $BBD2
map_control_0dbbd2:
    .byte $E0 ; previous-row copy escape
    .byte $8E ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $5B ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $5D ; row-distance/count
