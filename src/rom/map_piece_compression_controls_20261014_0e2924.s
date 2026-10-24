.setcpu "65816"
.segment "CODE"
.org $2924
map_control_0e2924:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
