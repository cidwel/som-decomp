.setcpu "65816"
.segment "CODE"
.org $2009
map_control_0f2009:
    .byte $EF ; backreference distance high bits
    .byte $0D ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
