.setcpu "65816"
.segment "CODE"
.org $ECCD
map_control_0deccd:
    .byte $E9 ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
