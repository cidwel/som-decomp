.setcpu "65816"
.segment "CODE"
.org $6472
map_control_0d6472:
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
    .byte $EB ; backreference distance high bits
    .byte $86 ; distance low bit/count
