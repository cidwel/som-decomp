.setcpu "65816"
.segment "CODE"
.org $D3F3
map_control_0dd3f3:
    .byte $EF ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
