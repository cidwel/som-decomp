.setcpu "65816"
.segment "CODE"
.org $1609
map_control_0d1609:
    .byte $EB ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $97 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
