.setcpu "65816"
.segment "CODE"
.org $BED8
map_control_0fbed8:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
