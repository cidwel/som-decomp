.setcpu "65816"
.segment "CODE"
.org $314E
map_control_0d314e:
    .byte $EC ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $59 ; row-distance/count
