.setcpu "65816"
.segment "CODE"
.org $0F6E
map_control_0e0f6e:
    .byte $EF ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
