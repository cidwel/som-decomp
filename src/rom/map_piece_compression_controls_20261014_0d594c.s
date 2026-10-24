.setcpu "65816"
.segment "CODE"
.org $594C
map_control_0d594c:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $E1 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
