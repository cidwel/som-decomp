.setcpu "65816"
.segment "CODE"
.org $D121
map_control_0fd121:
    .byte $EF ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
