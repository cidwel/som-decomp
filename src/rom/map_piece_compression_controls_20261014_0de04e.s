.setcpu "65816"
.segment "CODE"
.org $E04E
map_control_0de04e:
    .byte $E0 ; previous-row copy escape
    .byte $BA ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $92 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $FF ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $FF ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $E7 ; row-distance/count
