.setcpu "65816"
.segment "CODE"
.org $CABF
map_control_0ecabf:
    .byte $E0 ; previous-row copy escape
    .byte $AD ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
