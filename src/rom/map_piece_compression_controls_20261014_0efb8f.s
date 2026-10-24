.setcpu "65816"
.segment "CODE"
.org $FB8F
map_control_0efb8f:
    .byte $EB ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
