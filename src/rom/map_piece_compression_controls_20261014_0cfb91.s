.setcpu "65816"
.segment "CODE"
.org $FB91
map_control_0cfb91:
    .byte $EF ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
