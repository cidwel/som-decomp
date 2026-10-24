.setcpu "65816"
.segment "CODE"
.org $2616
map_control_0f2616:
    .byte $EE ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
