.setcpu "65816"
.segment "CODE"
.org $BE0B
map_control_0dbe0b:
    .byte $EF ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $2F ; row-distance/count
