.setcpu "65816"
.segment "CODE"
.org $FB86
map_control_0cfb86:
    .byte $EF ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
