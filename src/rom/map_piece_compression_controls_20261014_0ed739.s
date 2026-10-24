.setcpu "65816"
.segment "CODE"
.org $D739
map_control_0ed739:
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $93 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count
