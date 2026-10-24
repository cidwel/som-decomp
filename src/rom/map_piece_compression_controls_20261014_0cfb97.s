.setcpu "65816"
.segment "CODE"
.org $FB97
map_control_0cfb97:
    .byte $EF ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
