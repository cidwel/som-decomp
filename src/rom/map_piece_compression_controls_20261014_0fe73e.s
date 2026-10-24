.setcpu "65816"
.segment "CODE"
.org $E73E
map_control_0fe73e:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
