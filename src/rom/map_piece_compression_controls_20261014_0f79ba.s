.setcpu "65816"
.segment "CODE"
.org $79BA
map_control_0f79ba:
    .byte $E9 ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
