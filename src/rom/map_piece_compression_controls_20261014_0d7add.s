.setcpu "65816"
.segment "CODE"
.org $7ADD
map_control_0d7add:
    .byte $E0 ; previous-row copy escape
    .byte $4D ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $52 ; row-distance/count
