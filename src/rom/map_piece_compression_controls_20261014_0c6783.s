.setcpu "65816"
.segment "CODE"
.org $6783
map_control_0c6783:
    .byte $EF ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
