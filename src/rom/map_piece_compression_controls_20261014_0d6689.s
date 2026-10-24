.setcpu "65816"
.segment "CODE"
.org $6689
map_control_0d6689:
    .byte $EF ; backreference distance high bits
    .byte $8E ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
