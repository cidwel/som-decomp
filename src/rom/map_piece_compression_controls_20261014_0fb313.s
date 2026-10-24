.setcpu "65816"
.segment "CODE"
.org $B313
map_control_0fb313:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
    .byte $EF ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
