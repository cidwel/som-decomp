.setcpu "65816"
.segment "CODE"
.org $550E
map_control_0e550e:
    .byte $E3 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $22 ; row-distance/count
