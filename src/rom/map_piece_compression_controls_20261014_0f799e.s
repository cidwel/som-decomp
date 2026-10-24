.setcpu "65816"
.segment "CODE"
.org $799E
map_control_0f799e:
    .byte $EF ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $24 ; row-distance/count
