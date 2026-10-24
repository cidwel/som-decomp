.setcpu "65816"
.segment "CODE"
.org $EB9F
map_control_0deb9f:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
