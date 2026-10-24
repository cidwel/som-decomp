.setcpu "65816"
.segment "CODE"
.org $79EF
map_control_0d79ef:
    .byte $EC ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $24 ; row-distance/count
