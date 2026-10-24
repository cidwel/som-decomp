.setcpu "65816"
.segment "CODE"
.org $78C8
map_control_0d78c8:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
