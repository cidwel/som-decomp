.setcpu "65816"
.segment "CODE"
.org $C208
map_control_0ec208:
    .byte $E8 ; backreference distance high bits
    .byte $AD ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $AF ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $2F ; row-distance/count
