.setcpu "65816"
.segment "CODE"
.org $B707
map_control_0fb707:
    .byte $EE ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
