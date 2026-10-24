.setcpu "65816"
.segment "CODE"
.org $D01F
map_control_0fd01f:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
