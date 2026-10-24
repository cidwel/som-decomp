.setcpu "65816"
.segment "CODE"
.org $FC1C
map_control_0efc1c:
    .byte $E0 ; previous-row copy escape
    .byte $91 ; row-distance/count
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
