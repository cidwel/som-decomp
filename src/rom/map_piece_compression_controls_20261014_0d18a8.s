.setcpu "65816"
.segment "CODE"
.org $18A8
map_control_0d18a8:
    .byte $F1 ; progressive-copy count
    .byte $DA ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $90 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
