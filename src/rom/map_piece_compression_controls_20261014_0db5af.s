.setcpu "65816"
.segment "CODE"
.org $B5AF
map_control_0db5af:
    .byte $E8 ; backreference distance high bits
    .byte $16 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $FF ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $67 ; row-distance/count
