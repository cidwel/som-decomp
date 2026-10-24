.setcpu "65816"
.segment "CODE"
.org $6A79
map_control_0f6a79:
    .byte $EF ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $38 ; row-distance/count
