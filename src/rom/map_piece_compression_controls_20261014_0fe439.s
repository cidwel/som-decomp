.setcpu "65816"
.segment "CODE"
.org $E439
map_control_0fe439:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
