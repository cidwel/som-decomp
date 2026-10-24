.setcpu "65816"
.segment "CODE"
.org $F430
map_control_0ef430:
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
    .byte $EF ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $29 ; row-distance/count
